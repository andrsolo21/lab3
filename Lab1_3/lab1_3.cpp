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

	connect(ui.but5_3, SIGNAL(clicked()), this, SLOT(cancel()));
	connect(ui.but7_3, SIGNAL(clicked()), this, SLOT(deleteCar()));

	connect(ui.but4_3, SIGNAL(clicked()), this, SLOT(cancel()));
	connect(ui.but8_3, SIGNAL(clicked()), this, SLOT(deletePres()));

	connect(ui.comboPress_3, SIGNAL(currentIndexChanged(int)), this, SLOT(iDo6(int)));
	connect(ui.comboBoxCar_3, SIGNAL(currentIndexChanged(int)), this, SLOT(iDo5(int)));

	//connect(ui.delAll_3, SIGNAL(clicked()), this, SLOT(deleteAll()));


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
	//ui.delAllCars_3->setFixedSize(width() / 4 - 4 * ots, hig);
	//ui.delAllPres_3->setFixedSize(width() / 4 - 4 * ots, hig);
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

	//ui.comboBox_3->setFixedSize(width() / 4 - 4 * ots, hig);
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

void Lab1_3::comboCar() {
	ui.comboBoxCar_3->clear();
	ui.comboBoxCar_3->setEnabled(true);
	int count = 0;
	for (auto i = 0; i < _motors->getCount(); i++) {
		if ((*(*_motors)[i])->getType()) {
			count++;
			ui.comboBoxCar_3->addItem(((*(*_motors)[i])->getName()) + " Num: " +  QString::number(i), QVariant(i));
		}
	}
	if (count == 0) {
		ui.comboBoxCar_3->setEnabled(false);
	}

}

void Lab1_3::comboPres() {
	ui.comboPress_3->clear();
	ui.comboPress_3->setEnabled(true);
	int count = 0;
	for (auto i = 0; i < _motors->getCount(); i++) {
		if (!((*(*_motors)[i])->getType())) {
			count++;
			ui.comboPress_3->addItem(((*(*_motors)[i])->getName()) + " Num: " + QString::number(i), QVariant(i));
		}
	}
	if (count == 0) {
		ui.comboPress_3->setEnabled(false);
	}
}

void Lab1_3::cancel() {
	ui.groupCar->setVisible(false);
	ui.groupPres->setVisible(false);
}


Car * Lab1_3::getCar() {
	float coord[2], gabarites[2], angle;
	bool ok[5];
	coord[0] = (ui.coordXLine_3->text()).toFloat(&ok[0]);
	coord[1] = (ui.coordYLine_3->text()).toFloat(&ok[1]);
	gabarites[0] = (ui.gabXLine_3->text()).toFloat(&ok[2]);
	gabarites[1] = (ui.gabYLine_3->text()).toFloat(&ok[3]);
	QString name = ui.nameAddLine_3->text();
	angle = (ui.angleLine_3->text()).toFloat(&ok[4]);
	Car * car = NULL;
	if ((!name.isEmpty()) && ok[0] && ok[1] && ok[2] && ok[3] && ok[4]) {
		car = new Car(name, angle, gabarites, coord);
	}
	return car;
}

void Lab1_3::deleteCar() {
	int index = ui.comboBoxCar_3->currentData().toInt();
	_motors->deleteElement(index);
	update();
	comboCar();
	iDo5();
}

void Lab1_3::setCar() {
	Car * car = getCar();
	if (car) {
		_motors->addEl(car);
	}
	update();
}

void Lab1_3::changeCar() {
	Car * car = getCar();
	if (car) {
		int index = ui.comboBoxCar_3->currentData().toInt();
		_motors->changeEl(car, index);
	}
	update();
}


NoCar * Lab1_3::getPres() {
	float coord[2], radius;
	bool ok1, ok2, ok3;
	//int index = ui.comboBox->currentData().toInt();
	coord[0] = (ui.coordPresX_3->text()).toFloat(&ok1);
	coord[1] = (ui.coordPresY_3->text()).toFloat(&ok2);
	QString name = ui.namePresLine_3->text();
	radius = (ui.radiusPresLine_3->text()).toFloat(&ok3);
	NoCar * noCar = NULL;
	if ((!name.isEmpty()) && ok1 && ok2 && ok3) {
		noCar = new NoCar(name,radius, coord);
	}
	return noCar;
}

void Lab1_3::deletePres() {
	int i, index = ui.comboBoxCar_3->currentData().toInt();
	for (i = 0; i < _motors->getCount() && index >= 0; i++)
		if (!((*((*_motors)[i]))->getType()))
			index--;
	_motors->deleteElement(i - 1);
	update();
	comboPres();
	iDo6();
}

void Lab1_3::setPres() {
	NoCar * noCar = getCar();
	if (noCar)
	{
		_motors->addEl(noCar);
	}
	update();
}

void Lab1_3::changePres() {
	NoCar * noCar = getPres();
	if (noCar) {
		int i, index = ui.comboBoxCar_3->currentData().toInt();
		for (i = 0; i < _motors->getCount() && index >= 0; i++)
			if (!((*((*_motors)[i]))->getType()))
				index--;
		int index = ui.comboBoxCar_3->currentData().toInt();
		_motors->changeEl(noCar, i-1);
	}
	update();
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
		iDo2();
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
		iDo3();
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
		comboCar();
		iDo5();
		ui.but5_3->setText(QString::fromLocal8Bit("change"));
		//disconnect(ui.but2_3, SIGNAL(clicked()), this, SLOT(setCar()));
		//connect(ui.but2_3, SIGNAL(clicked()), this, SLOT(changeCar()));
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
		comboPres();
		//disconnect(ui.but3_3, SIGNAL(clicked()), this, SLOT(setPres()));
		//connect(ui.but3_3, SIGNAL(clicked()), this, SLOT(changePres()));
	}
}


void Lab1_3::iDo2() {
	ui.but7_3->setVisible(false);
	ui.comboBoxCar_3->setVisible(false);

	ui.nameAddLine_3->setEnabled(true);
	ui.angleLine_3->setEnabled(true);
	ui.coordXLine_3->setEnabled(true);
	ui.gabXLine_3->setEnabled(true);
	ui.coordYLine_3->setEnabled(true);
	ui.gabYLine_3->setEnabled(true);
	ui.but2_3->setEnabled(true);
	ui.but5_3->setEnabled(true);

	ui.nameAddLine_3->clear();
	ui.angleLine_3->clear();
	ui.coordXLine_3->clear();
	ui.gabXLine_3->clear();
	ui.coordYLine_3->clear();
	ui.gabYLine_3->clear();
	ui.but2_3->setText(QString::fromLocal8Bit("add"));
	//disconnect(ui.but2_3, SIGNAL(clicked()), this, SLOT(changeCar()));
	//connect(ui.but2_3, SIGNAL(clicked()), this, SLOT(setCar()));
}

void Lab1_3::iDo3() {
	ui.namePresLine_3->setEnabled(true);
	ui.radiusPresLine_3->setEnabled(true);
	ui.coordPresX_3->setEnabled(true);
	ui.coordPresY_3->setEnabled(true);
	ui.but3_3->setEnabled(true);
	ui.but4_3->setEnabled(true);

	ui.comboPress_3->setVisible(false);
	ui.but8_3->setVisible(false);

	ui.namePresLine_3->clear();
	ui.radiusPresLine_3->clear();
	ui.coordPresX_3->clear();
	ui.coordPresY_3->clear();
	ui.but3_3->setText(QString::fromLocal8Bit("add"));
	//disconnect(ui.but3_3, SIGNAL(clicked()), this, SLOT(changePres()));
	//connect(ui.but3_3, SIGNAL(clicked()), this, SLOT(setPres()));
}

void Lab1_3::iDo5(int k) {	
	
	if (ui.comboBoxCar_3->isEnabled()) {
		NoCar * car;
		int index = ui.comboBoxCar_3->currentData().toInt();
		car = *((*_motors)[index]);
		ui.nameAddLine_3->setEnabled(true);
		ui.angleLine_3->setEnabled(true);
		ui.coordXLine_3->setEnabled(true);
		ui.gabXLine_3->setEnabled(true);
		ui.coordYLine_3->setEnabled(true);
		ui.gabYLine_3->setEnabled(true);
		ui.but2_3->setEnabled(true);
		ui.but5_3->setEnabled(true);

		ui.nameAddLine_3->setText(car->getName());
		ui.angleLine_3->setText(QString::number(car->getAngle()));
		ui.coordXLine_3->setText(QString::number(car->getCoord(0)));
		ui.gabXLine_3->setText(QString::number(car->getSize(0)));
		ui.coordYLine_3->setText(QString::number(car->getCoord(1)));
		ui.gabYLine_3->setText(QString::number(car->getSize(1)));
	}
	else {
		ui.nameAddLine_3->clear();
		ui.angleLine_3->clear();
		ui.coordXLine_3->clear();
		ui.gabXLine_3->clear();
		ui.coordYLine_3->clear();
		ui.gabYLine_3->clear();
		ui.nameAddLine_3->setEnabled(false);
		ui.angleLine_3->setEnabled(false);
		ui.coordXLine_3->setEnabled(false);
		ui.gabXLine_3->setEnabled(false);
		ui.coordYLine_3->setEnabled(false);
		ui.gabYLine_3->setEnabled(false);
		ui.but2_3->setEnabled(false);
		ui.but5_3->setEnabled(false);
		ui.but7_3->setEnabled(false);
	}
}

void Lab1_3::iDo6(int k) {
	if (ui.comboPress_3->isEnabled()) {
		ui.namePresLine_3->setEnabled(true);
		ui.radiusPresLine_3->setEnabled(true);
		ui.coordPresX_3->setEnabled(true);
		ui.coordPresY_3->setEnabled(true);
		ui.but3_3->setEnabled(true);
		ui.but4_3->setEnabled(true);
		ui.but8_3->setEnabled(true);
		
		int i, index = ui.comboBoxCar_3->currentData().toInt();
		for (i = 0; i < _motors->getCount() && index >= 0; i++)
			if (!((*((*_motors)[i]))->getType()))
				index--;
		NoCar * car = *((*_motors)[i-1]);
		ui.namePresLine_3->setText(car->getName());
		ui.radiusPresLine_3->setText(QString::number((car->getR())));
		ui.coordPresX_3->setText(QString::number(car->getCoord(0)));
		ui.coordPresY_3->setText(QString::number(car->getCoord(1)));
	}
	else {
		ui.namePresLine_3->clear();
		ui.radiusPresLine_3->clear();
		ui.coordPresX_3->clear();
		ui.coordPresY_3->clear();
		ui.namePresLine_3->setEnabled(false);
		ui.radiusPresLine_3->setEnabled(false);
		ui.coordPresX_3->setEnabled(false);
		ui.coordPresY_3->setEnabled(false);
		ui.but3_3->setEnabled(false);
		ui.but4_3->setEnabled(false);
		ui.but8_3->setEnabled(false);
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