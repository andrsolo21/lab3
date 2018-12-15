#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_lab1_3.h"
#include <QPainter>
#include <QPushButton>
#include <QLineEdit>
#include <math.h>
#include "MotorShow.h"



class Lab1_3 : public QMainWindow
{
	Q_OBJECT

public:
	Lab1_3(QWidget *parent = Q_NULLPTR);

public slots:
	void slotBut();
	void getGabs();
	void doVisible1();
	void doVisible2();
	void doVisible3();
	void doVisible4();
	void doVisible5();
	void doVisible6();
	void reduce();
	void iDo6(int k = 1);
	void iDo5(int k = 1);
	void iDo3();
	void iDo2();
	void setCar();
	void setPres();
	void comboPres();
	void cancel();
	void deleteCar();
	void deletePres();
	void changeCar();
	void changePres();
	void printToFile() {
		_motors->exportToFile(ui.strToFile_3->text());
		ui.strToFile_3->clear();
	}
	void deleteAll();
	void radioGabsC();
	void radioFileC();

private:
	Ui::Lab1_3Class ui;
	int _gabarits[2] = { 0 ,0 }, _index;
	float _otn = 1;
	MotorShow *_motors = NULL;
	bool _btns = true;
	void comboCar();
	QPolygonF rectMy(qreal a, qreal b, const  QPointF& center, float alpha);
	void paintEvent(QPaintEvent *event);
	void setSize(int ots);
	void coonections();
	Circle * getPres();
	Car * getCar();
	void setEnabledMenu(bool value);
};
