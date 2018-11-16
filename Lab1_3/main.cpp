#include "stdafx.h"
#include "lab1_3.h"
#include <QtWidgets/QApplication>
#include "MotorShow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Lab1_3 w;
	w.show();
	return a.exec();
}
