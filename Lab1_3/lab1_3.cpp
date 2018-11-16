#include "stdafx.h"
#include "lab1_3.h"


bool fileIsExist(const std::string & filePath);

Lab1_3::Lab1_3(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.groupCar->setVisible(false);
	ui.groupPres->setVisible(false);
	ui.groupField->setVisible(false);
	ui.changeField->setVisible(false);
	ui.btnGroup->setVisible(true);
	coonections();
	slotBut();
}

void Lab1_3::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QPolygonF polygon, fon, fon1;
	int ots = 7;
	qreal gabs[2] = { 0,0 };
	if (width() < 30 || height() < min(30, 3 * ots + 1))
		return;

	setSize(ots);
	QPointF center, center2, center3;
	float w, h;
	//fon
	if (_btns) {
		w = (double)width() / 4 * 3 - ots * 2;
		h = height() - ots * 2;

		fon1 << QPointF(0, 0);
		fon1 << QPointF(width() / 4 * 3, 0);
		fon1 << QPointF(width() / 4 * 3, height());
		fon1 << QPointF(0, height());
		painter.setBrush(QBrush(Qt::lightGray));
		painter.setPen(QPen(Qt::lightGray));
		painter.drawPolygon(fon1);
	}
	else {
		w = width() - ots * 2;
		h = height() - ots * 2;

		fon1 << QPointF(0, 0);
		fon1 << QPointF(width(), 0);
		fon1 << QPointF(width(), height());
		fon1 << QPointF(0, height());
		painter.setBrush(QBrush(Qt::lightGray));
		painter.setPen(QPen(Qt::lightGray));
		painter.drawPolygon(fon1);
	}
	//pole
	if (_gabarits[1] == 0) {
		fon << QPointF(ots, ots);
		fon << QPointF(ots + w, ots);
		fon << QPointF(ots + w, ots + h);
		fon << QPointF(ots, ots + h);
		painter.setPen(QPen(Qt::gray));
		painter.setBrush(QBrush(Qt::gray));
	}
	else {
		float otn0 = w / _gabarits[0];
		float otn1 = h / _gabarits[1];
		center = QPointF(w / 2 + ots, h / 2 + ots);
		float alpha = 0;
		if (otn0 < otn1) {
			_otn = otn0;
			gabs[0] = w;
			gabs[1] = w / _gabarits[0] * _gabarits[1];
		}
		else {
			_otn = otn1;
			gabs[1] = h;
			gabs[0] = h / _gabarits[1] * _gabarits[0];
		}
		fon = rectMy(gabs[0], gabs[1], center, alpha);
		painter.setPen(QPen(Qt::black));
		painter.setBrush(QBrush(Qt::white));
	}
	painter.drawPolygon(fon);
	/*if (_motors != NULL) {
		for (int i = 0; i < _motors->getCountP(); i++) {
			painter.setBrush(QBrush(Qt::blue));
			center2 = QPointF((_motors->getPres(i)).getCoord(0) * _otn + center.x() - gabs[0] / 2,
				(_motors->getPres(i)).getCoord(1)* _otn + center.y() - gabs[1] / 2);

			painter.drawEllipse(center2, (_motors->getPres(i)).getR() * _otn, (_motors->getPres(i)).getR() * _otn);

			painter.setBrush(QBrush(Qt::green));
			for (int j = 0; j < (_motors->getPres(i)).getCount(); j++) {

				center3 = QPointF((_motors->getPres(i))[j].getCoord(0) * _otn + center2.x(),
					(_motors->getPres(i))[j].getCoord(1)* _otn + center2.y());

				polygon = rectMy((_motors->getPres(i))[j].getSize(0) * _otn, (_motors->getPres(i))[j].getSize(1) * _otn,
					center3, (_motors->getPres(i))[j].getAngle());
				painter.drawPolygon(polygon);
			}
		}
	}*/

	//main drawing
	Car * tempCar;
	NoCar  tempNoCar;
	if (_motors != NULL) {
		painter.setPen(QPen(Qt::black));
		//circle
		painter.setBrush(QBrush(Qt::blue));
		for (auto i = 0; i < _motors->getCount(); i++) {
			if (!((*(*_motors)[i])->getType())) {
				tempNoCar = **(*_motors)[i];
				center2 = QPointF(tempNoCar.getCoord(0) * _otn + center.x() - gabs[0] / 2,
					tempNoCar.getCoord(1)* _otn + center.y() - gabs[1] / 2);
				painter.drawEllipse(center2, tempNoCar.getR() * _otn, tempNoCar.getR() * _otn);
			}
		}
		//rect
		painter.setBrush(QBrush(Qt::yellow));
		for (auto i = 0; i < _motors->getCount(); i++) {
			if ((*(*_motors)[i])->getType()) {
				tempCar = new Car;
				*tempCar = **(*_motors)[i];

				center2 = QPointF((*(*_motors)[i])->getCoord(0) * _otn + center.x() - gabs[0] / 2,
					(*(*_motors)[i])->getCoord(1)* _otn + center.y() - gabs[1] / 2);

				polygon = rectMy((*(*_motors)[i])->getSize(0) * _otn, (*(*_motors)[i])->getSize(1) * _otn, center2,
					(*(*_motors)[i])->getAngle());
				painter.drawPolygon(polygon);
				delete tempCar;
			}
		}
	}
}

void Lab1_3::coonections() {
	connect(ui.but_3, SIGNAL(clicked()), this, SLOT(slotBut()));
	//connect(ui.printBtn, SIGNAL(clicked()), this, SLOT(printToFile()));
	connect(ui.reduceBut, SIGNAL(clicked()), this, SLOT(reduce()));

	connect(ui.addFieldBut_3, SIGNAL(clicked()), this,  SLOT(doVisible1()));
	connect(ui.addCarBut_3, SIGNAL(clicked()), this, SLOT(doVisible2()));
	connect(ui.addPresBut_3, SIGNAL(clicked()), this, SLOT(doVisible3()));
	connect(ui.changeFieldBut_3, SIGNAL(clicked()), this, SLOT(doVisible4()));
	connect(ui.changeCarBut_3, SIGNAL(clicked()), this, SLOT(doVisible5()));
	connect(ui.changePressBut_3, SIGNAL(clicked()), this, SLOT(doVisible6()));

	/*connect(ui.but5, SIGNAL(clicked()), this, SLOT(cancelCar()));
	connect(ui.but7, SIGNAL(clicked()), this, SLOT(deleteThisCar()));

	connect(ui.but4, SIGNAL(clicked()), this, SLOT(cancelPres()));
	connect(ui.but8, SIGNAL(clicked()), this, SLOT(deleteThisPres()));*/

	/*connect(ui.comboPress, SIGNAL(currentIndexChanged(int)), this, SLOT(iDo6(int)));
	//connect(ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboSelectItem(int)));
	connect(ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboCar(int)));
	connect(ui.comboBoxCar, SIGNAL(currentIndexChanged(int)), this, SLOT(iDo5(int)));*/

	/*connect(ui.delAllCars, SIGNAL(clicked()), this, SLOT(deleteAllElements()));
	connect(ui.delAllPres, SIGNAL(clicked()), this, SLOT(deleteAllPres()));
	connect(ui.delAll, SIGNAL(clicked()), this, SLOT(deleteAll()));*/


	//connect(ui.comboBox, SIGNAL(activated(int)), this, SLOT(comboSelectItem(int)));
	//connect(ui.whatDoCars, SIGNAL(currentIndexChanged(int)), this, SLOT(iDoCars(int)));
}

void Lab1_3::slotBut() {
	if (fileIsExist((ui.lineEdit_3->text()).toStdString())) {
		std::string s = (ui.lineEdit_3->text()).toStdString();
		ui.lineEdit_3->clear();
		delete _motors;
		_motors = new MotorShow(s);
		_gabarits[0] = _motors->getGabarits(0);
		_gabarits[1] = _motors->getGabarits(1);
		//comboboxAdd();
		update();
	}
}

void Lab1_3::setSize(int ots) {
	int w = width(), h = height();

	QRect a = { w / 4 * 3 + ots, h / 3 + ots,
		w / 4 - 2 * ots, h * 2 / 3 };
	QRect b = { w / 4 * 3 + ots, ots,
		w / 4 - 2 * ots, h / 3 };
	int hig = 23;

	ui.btnGroup->setGeometry(b);

	ui.groupField->setGeometry(a);
	ui.lineEdit_3->setFixedSize(width() / 4 - 4 * ots, hig);
	ui.but_3->setFixedSize(width() / 4 - 4 * ots, hig);
	ui.delAll_3->setFixedSize(width() / 4 - 4 * ots, hig);
	ui.delAllCars_3->setFixedSize(width() / 4 - 4 * ots, hig);
	ui.delAllPres_3->setFixedSize(width() / 4 - 4 * ots, hig);
	ui.strToFile_3->setFixedSize(width() / 4 - 4 * ots, hig);
	ui.printBtn_3->setFixedSize(width() / 4 - 4 * ots, hig);


	ui.changeField->setGeometry(a);
	ui.addFieldBut_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.changeFieldBut_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.addCarBut_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.changeCarBut_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.addPresBut_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.changePressBut_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);

	ui.groupCar->setGeometry(a);

	ui.comboBox_3->setFixedSize(width() / 4 - 4 * ots, hig);
	ui.comboBoxCar_3->setFixedSize(width() / 4 - 4 * ots, hig);
	ui.nameAddLine_3->setFixedSize(width() / 4 - 4 * ots, hig);
	ui.angleLine_3->setFixedSize(width() / 4 - 4 * ots, hig);
	ui.coordXLine_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.coordYLine_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.gabXLine_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.gabYLine_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.but5_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.but2_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.but7_3->setFixedSize(width() / 4 - 4 * ots, hig);

	ui.groupPres->setGeometry(a);
	ui.comboPress_3->setFixedSize(width() / 4 - 4 * ots, hig);
	ui.namePresLine_3->setFixedSize(width() / 4 - 4 * ots, hig);
	ui.radiusPresLine_3->setFixedSize(width() / 4 - 4 * ots, hig);
	ui.coordPresX_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.coordPresY_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.but3_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.but4_3->setFixedSize((width() / 4 - 4 * ots) / 2 - ots / 2, hig);
	ui.but8_3->setFixedSize(width() / 4 - 4 * ots, hig);

	//ui.groupCar->setVisible(false);
	//ui.groupPres->setVisible(false);
	//ui.groupField->setVisible(false);
	//ui.btnGroup->setVisible(false);

	//ui.groupCar->setVisible(true);
	//ui.groupPres->setVisible(true);
	//ui.groupField->setVisible(true);
	//ui.btnGroup->setVisible(true);

	//ui.gabXLine->resize(width() / 4 - ots, height() - ots * 3);
	//ui.gabYLine->resize(width() / 4 - ots, height() - ots * 3);
	//ui.angleLine->resize();
}

void Lab1_3::doVisible1() {

	if (ui.groupField->isVisible())
		ui.groupField->setVisible(false);
	else  {
		ui.groupCar->setVisible(false);
		ui.groupPres->setVisible(false);
		ui.groupField->setVisible(true);
		ui.changeField->setVisible(false);
	}
}

void Lab1_3::doVisible2() {

	if (ui.groupCar->isVisible() && !(ui.but7_3->isVisible()))
		ui.groupCar->setVisible(false);
	else {
		ui.groupCar->setVisible(true);
		ui.groupPres->setVisible(false);
		ui.groupField->setVisible(false);
		ui.changeField->setVisible(false);
		//iDo2();
	}
}

void Lab1_3::doVisible3() {

	if (ui.groupPres->isVisible() && !(ui.comboPress_3->isVisible()))
		ui.groupPres->setVisible(false);
	else {
		ui.groupCar->setVisible(false);
		ui.groupPres->setVisible(true);
		ui.groupField->setVisible(false);
		ui.changeField->setVisible(false);
		//iDo3();
	}
}

void Lab1_3::doVisible4() {

	if (ui.changeField->isVisible())
		ui.changeField->setVisible(false);
	else {
		ui.groupCar->setVisible(false);
		ui.groupPres->setVisible(false);
		ui.groupField->setVisible(false);
		ui.changeField->setVisible(true);
	}
}

void Lab1_3::doVisible5() {

	if (ui.groupCar->isVisible() && ui.but7_3->isVisible())
		ui.groupCar->setVisible(false);
	else {
		ui.groupCar->setVisible(true);
		ui.groupPres->setVisible(false);
		ui.groupField->setVisible(false);
		ui.changeField->setVisible(false);
		ui.but7_3->setVisible(true);
		ui.comboBoxCar_3->setVisible(true);
		//iDo5();
		ui.but5_3->setText(QString::fromLocal8Bit("change"));
		disconnect(ui.but2_3, SIGNAL(clicked()), this, SLOT(setCar()));
		connect(ui.but2_3, SIGNAL(clicked()), this, SLOT(changeCar()));
	}
}

void Lab1_3::doVisible6() {

	if (ui.groupPres->isVisible() && ui.comboPress_3->isVisible())
		ui.groupPres->setVisible(false);
	else {
		ui.groupCar->setVisible(false);
		ui.groupPres->setVisible(true);
		ui.groupField->setVisible(false);
		ui.changeField->setVisible(false);
		ui.comboPress_3->setVisible(true);
		ui.but8_3->setVisible(true);
		//iDo6();
		ui.but3_3->setText(QString::fromLocal8Bit("change"));
		disconnect(ui.but3_3, SIGNAL(clicked()), this, SLOT(setPres()));
		connect(ui.but3_3, SIGNAL(clicked()), this, SLOT(changePres()));
	}
}

void Lab1_3::reduce() {
	if (_btns)
	{
		_btns = false;
		ui.groupCar->setVisible(false);
		ui.groupPres->setVisible(false);
		ui.groupField->setVisible(false);
		ui.btnGroup->setVisible(false);
	}
	else {

		ui.btnGroup->setVisible(true);
		_btns = true;
	}
	update();
}

QPolygonF Lab1_3::rectMy(qreal a, qreal b, const  QPointF& center, float alpha) {
	float radius2;
	QPolygonF polygon;
	radius2 = sqrt(pow(a / 2, 2) + pow(b / 2, 2));
	float betta;
	if (b > a) {
		betta = atan(b / a);
	}
	else {
		betta = M_PI / 2 - atan(a / b);
	}
	float mass[4] = { betta, M_PI - betta, M_PI + betta, -betta };

	for (int i = 0; i < 4; i++) {
		qreal fAngle = mass[i] - (alpha / 360) * 2 * M_PI;
		qreal x = center.x() + cos(fAngle)*radius2;
		qreal y = center.y() + sin(fAngle)*radius2;
		polygon << QPointF(x, y);
	}
	return polygon;
}

bool fileIsExist(const std::string & filePath)
{
	bool isExist = false;
	std::ifstream fin(filePath.c_str());

	if (fin.is_open())
		isExist = true;

	fin.close();
	return isExist;
}