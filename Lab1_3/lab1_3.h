#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_lab1_3.h"
#include <QPainter>
#include <QPushButton>
#include <QLineEdit>
#include <math.h>
#include "MotorShow.h"
# define M_PI           3.14159265358979323846


class Lab1_3 : public QMainWindow
{
	Q_OBJECT

public:
	Lab1_3(QWidget *parent = Q_NULLPTR);

public slots:
	void slotBut();
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

private:
	Ui::Lab1_3Class ui;
	int _gabarits[2] = { 0 ,0 };
	float _otn = 1;
	MotorShow *_motors = NULL;
	bool _btns = true;
	void comboCar();
	QPolygonF rectMy(qreal a, qreal b, const  QPointF& center, float alpha);
	void paintEvent(QPaintEvent *event);
	void setSize(int ots);
	void coonections();
	NoCar * getPres();
	Car * getCar();
	
};
