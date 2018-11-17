#include "stdafx.h"
#include "MotorShow.h"
#include <fstream> 
#include <cstdio>

MotorShow::MotorShow()
{
	_head = NULL;
	_tail = NULL;
	_grr = 0;
	_gabarits[0] = 10;
	_gabarits[1] = 10;

}

/*MotorShow::MotorShow(Car * addData[], int addCount, float addGabarits[]) {
	_head = NULL;
	_tail = NULL;
	_grr = 0;
	if (addGabarits[0] > 0 && addGabarits[1] > 0) {
		_gabarits[0] = addGabarits[0];
		_gabarits[1] = addGabarits[1];
	}

	grow10(addCount);
	for (int i = 0; i < addCount; i++) {
		addCar(*addData[i]);
	}
}*/

MotorShow::MotorShow(const MotorShow & addData) {
	_head = NULL;
	_tail = NULL;
	_grr = 0;
	_gabarits[0] = addData.getGabarits(0);
	_gabarits[1] = addData.getGabarits(1);
	grow10(addData.getCount());
	for (int i = 0; i < addData.getCount(); i++) {
		if ((*addData[i])->getType()) {
			Car * tempCar = new Car;
			*tempCar = **addData[i];
			addEl(tempCar);
		}
		else {
			addEl(new NoCar(**addData[i]));
		}		
	}
}

MotorShow::MotorShow(std::string name) {
	_head = NULL;
	_tail = NULL;
	_grr = 0;
	int n;
	ifstream file(name);
	if (file.is_open())
	{
		file >> n;
		grow10(n);
		file >> _gabarits[0];
		file >> _gabarits[1];
		std::string type, s;		
		float size[2], coord[2], angle;
		for (file >> type; !file.eof(); file >> type) {
			if (type == "car") {
				file >> s >> size[0] >> size[1] >> angle >> coord[0] >> coord[1];
				addEl(new Car(QString::fromStdString(s), angle, size, coord));
			}
			if (type == "pres") {
				file >> s >> angle >> coord[0] >> coord[1];
				addEl(new NoCar(QString::fromStdString(s), angle, coord));
			}		
		}
		file.close();
	}

}

void MotorShow::exportToFile(QString name) {
	ofstream fout(name.toStdString(), ios_base::out | ios_base::trunc);
	fout << (_tail - _head) << endl;
	fout << _gabarits[0] << ' ';
	fout << _gabarits[1];
	for (auto i = _head; i < _tail; i++) {
		if ((*i)->getType()) {
			fout << endl << "car";
			fout << endl << ((*i)->getName()).toStdString() << endl;
			fout << (*i)->getSize(0) << ' ' << (*i)->getSize(1) << ' ' << (*i)->getAngle() <<
				' ' << (*i)->getCoord(0) << ' ' << (*i)->getCoord(1);
		}
		else {
			fout << endl << "pres";
			fout << endl << ((*i)->getName()).toStdString() << endl;
			fout <<(*i)->getR() <<' ' << (*i)->getCoord(0) << ' ' << (*i)->getCoord(1);
		}		
	}
	fout.close();
}

NoCar ** MotorShow::operator [](int c) const
{
	if (c < (_tail - _head) && c >= 0) {
		return _head + c;
	}
	else
		throw std::exception("index out of range");
}

float MotorShow::getGabarits(int i) const {
	return _gabarits[i % 2];
}

int MotorShow::getCount() const {
	return (_tail - _head);
}

void MotorShow::addEl(NoCar * element) {
	if (checkEl(*element)) {
		grow10();		
		*(_tail) = element;
		_tail = _tail + 1;
	}
}

/*void MotorShow::addEl(Car * element) {
	if (checkEl(*element)) {
		grow10();
		*(_tail) = element;
		_tail = _tail + 1;
	}
}*/

void MotorShow::deleteElement(int c) {
	if (c < (_tail - _head) && c >= 0) {
		delete *(_head + c);
		for (auto i = _head + c; i < _tail - 1; i++)
			*i = *(i + 1);
		_tail--;
	}
}

void MotorShow::deleteAll() {
	for (auto i = _head; i < _tail; i++)
		delete *i;	
	delete[] _head;
	_tail = NULL;
	_head = NULL;
	_grr = 0;
}

void MotorShow::changeEl(NoCar * noCar, int c) {
	if (c >= 0 && c < getCount()) {
		NoCar  oldEl = **(_head + c);
		deleteElement(c);
		if (checkEl(*noCar)) {
			_tail++;
			for (auto i = _tail; i > (_head + c); i--)
				*i = *(i - 1);
			*(_head + c) = noCar;
		}
		else {
			_tail++;
			for (auto i = _tail; i > (_head + c); i--)
				*i = *(i - 1);
			*(_head + c) = &oldEl;
		}
	}
}

void MotorShow::grow10(int zn) {
	if (_grr == 0 || _tail - _head >= 10 * _grr - zn) {
		int startNum = 0;

		bool first = false;
		if (_grr == 0)
			first = true;

		if (zn % 10)
			_grr++;
		_grr += zn / 10;

		NoCar ** add = new NoCar*[10 * _grr];
		if (first) {
			_head = add;
			_tail = add;
		}
		else {
			int count = _tail - _head;
			for (auto i = 0; i < _tail - _head; i++) {
				*(add + i) = *(_head + i);
				//delete *(_head + i);
			}
			delete[] _head;
			_head = add;
			_tail = add + count;
		}
	}
}

bool MotorShow::checkEl(const NoCar & elToCheck) {
	
	if (elToCheck.getType()) {
		//машина
		return checkCar(elToCheck);
	}
	else {
		//стенд
		return checkP(elToCheck);
	}
}

bool MotorShow::checkCar(const NoCar & carToCheck) {
	float d;
	bool flag1, flag2, flag = true;
	float dots1[4][2];
	
	for (int j = 0; j < 2; j++) {
		dots1[0][j] = carToCheck.getA(j);
		dots1[1][j] = carToCheck.getB(j);
		dots1[2][j] = carToCheck.getC(j);
		dots1[3][j] = carToCheck.getD(j);
	}

	if (!checkGabarits(dots1))
		return false;

	for (auto ** i = _head; i < _tail; i++) {
		

		d = sqrt(pow((*i)->getCoord(0) - carToCheck.getCoord(0),2) + pow((*i)->getCoord(1) - carToCheck.getCoord(1),2));
		if ((*i)->getType()) {
			if ((*i)->getR() + carToCheck.getR() > d)
				return false;
			else {
				
				if ((*i)->getRBig() + carToCheck.getRBig() > d)
				{
					float dots2[4][2];
					for (int j = 0; j < 2; j++) {
						dots2[0][j] = (*i)->getA(j);
						dots2[1][j] = (*i)->getB(j);
						dots2[2][j] = (*i)->getC(j);
						dots2[3][j] = (*i)->getD(j);
					}
					flag1 = dots(dots1, dots2);
					flag2 = dots(dots2, dots1);
					if (flag1 == false && flag2 == false)
						return false;
				}
			}
		}
		else {
			if ((*i)->getR() + carToCheck.getRBig() > d) {
				d = 0;
				for (auto j = 0; j < 4; j++) 
					if (pow(dots1[j][0] - (*i)->getCoord(0), 2) + pow(dots1[j][1] - (*i)->getCoord(1), 2) 
						- pow((*i)->getR(), 2) < 0)
						d++;		
				if (d < 4)
					return false;
				else
					if ((*i)->getName() != carToCheck.getName())
						return false;
			}
		}
	}
	
	return true;
}

bool MotorShow::checkP(const NoCar & pToCheck) {
	float dots1[4][2], d;
	int count;
	for (int j = 0; j < 2; j++) {
		dots1[0][j] = pToCheck.getCoord(0) + pToCheck.getR();
		dots1[1][j] = pToCheck.getCoord(1) + pToCheck.getR();
		dots1[2][j] = pToCheck.getCoord(0) - pToCheck.getR();
		dots1[3][j] = pToCheck.getCoord(1) - pToCheck.getR();
	}
	if (!checkGabarits(dots1))
		return false;

	for (auto ** i = _head; i < _tail; i++) {
		d = sqrt(((*i)->getCoord(0) - pToCheck.getCoord(0)) * ((*i)->getCoord(0) - pToCheck.getCoord(0)) +
			((*i)->getCoord(1) - pToCheck.getCoord(1)) * ((*i)->getCoord(1) - pToCheck.getCoord(1)));
		if ((*i)->getType()) {
			if ((*i)->getRBig() + pToCheck.getR() > d) {
				count = 0;
				for (auto j = 0; j < 4; j++)
					if (pow(dots1[j][0] - (*i)->getCoord(0), 2) + pow(dots1[j][1] - (*i)->getCoord(1), 2)
						- pow((*i)->getR(), 2) < 0)
						count++;
				if (count < 4)
					return false;
			}
		}
		else {
			if ((*i)->getR() + pToCheck.getR() > d) {
				return false;
			}
		}		
	}
	return true;	
}

bool MotorShow::checkGabarits(float dots1[][2]) {
	for (int j = 0; j < 4; j++) {
		if (dots1[j][0] >= _gabarits[0])
			return false;
		if (dots1[j][1] >= _gabarits[1])
			return false;
		if (dots1[j][0] <= 0)
			return false;
		if (dots1[j][1] <= 0)
			return false;
	}
	return true;
}

float MotorShow::linear(float c[2], float a[2], float b[2]) {
	int mn = 1, x = 0, y = 0;
	if (b[0] != a[0])
		x = (c[0] - a[0]) / (b[0] - a[0]);
	else {
		x = 0;
		mn = 0;
	}
	if (b[1] != a[1])
		y = (c[1] - a[1]) / (b[1] - a[1]);
	else {
		y = 0;
		mn = 0;
	}
	return mn * (x - y);
}

int MotorShow::countDots(float a[2], float b[2], float rec[][2]) {
	int n = 0;
	float x;
	for (int i = 0; i < 4; i++) {
		x = linear(a, b, rec[i]);
		if (x < 0)
			n = n - 1;
		else
			n = n + 1;
	}
	return n;
}

bool MotorShow::dots(float dots11[][2], float dots12[][2]) {
	int n1, n2, m1, m2;
	n1 = countDots(dots11[0], dots11[1], dots12);
	n2 = countDots(dots11[3], dots11[2], dots12);
	m1 = countDots(dots11[0], dots11[3], dots12);
	m2 = countDots(dots11[1], dots11[2], dots12);
	if ((n1 == -4 && n2 == -4) || (n1 == 4 && n2 == 4) || (m1 == -4 && m2 == -4) || (m1 == 4 && m2 == 4))
		return true;
	return false;
}

MotorShow::~MotorShow()
{
}