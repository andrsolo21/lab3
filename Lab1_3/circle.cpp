#include "stdafx.h"
#include "circle.h"


Circle::Circle()
{
	_r = 3.11;
	_name = "defoltName";
	_coord[0] = 5.1111;
	_coord[1] = 5.1111;
}

Circle& Circle::operator = (NoCar car) {
	_name = car.getName();
	_r = car.getR();
	_coord[0] = car.getCoord(0);
	_coord[1] = car.getCoord(1);
	return *this;
}

Circle::Circle(QString nameAdd, float rAdd, float coordAdd[]) {
	if (nameAdd != "")
		_name = nameAdd;
	else {
		_name = "newCar";
	}
	if (rAdd > 0)
		_r = rAdd;
	_coord[0] = coordAdd[0];

	_coord[1] = coordAdd[1];
}

Circle::Circle(const Circle &addNo) {
	_name = addNo.getName();
	_r = addNo.getR();
	_coord[0] = addNo.getCoord(0);
	_coord[1] = addNo.getCoord(1);

}

Circle::Circle(const NoCar &addNo) {
	if (addNo.getType() == ci) {
		_name = addNo.getName();
		_r = addNo.getR();
		_coord[0] = addNo.getCoord(0);
		_coord[1] = addNo.getCoord(1);
	}

}

Circle::~Circle()
{
}
