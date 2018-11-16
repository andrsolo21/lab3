#include "stdafx.h"
#include "noCar.h"


NoCar::NoCar()
{
	_r = 3.11;
	_name = "defoltName";
	_coord[0] = 5.1111;
	_coord[1] = 5.1111;
}

NoCar::NoCar(QString nameAdd, float rAdd, float coordAdd[]) {
	if (nameAdd != "")
		_name = nameAdd;
	else {
		_name = "newCar";
	}
	if (rAdd>0)
		_r = rAdd;
	_coord[0] = coordAdd[0];

	_coord[1] = coordAdd[1];
}

NoCar::NoCar(const NoCar &addNo) {
	_name = addNo.getName();
	_r = addNo.getR();
	_coord[0] = getCoord(0);
	_coord[1] = getCoord(1);

}

QString NoCar::getName() const {
	return _name;
}

void NoCar::setName(QString nameAdd) {
	if (nameAdd != "")
		_name = nameAdd;
}

float NoCar::getCoord(int i) const {
	return _coord[i % 2];
}

float NoCar::getR() const {
	return _r;
}

void NoCar::setCoord(float coordAdd[]) {
	_coord[0] = coordAdd[0];
	_coord[1] = coordAdd[1];
}

NoCar::~NoCar()
{
}
