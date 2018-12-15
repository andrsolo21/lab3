#include "stdafx.h"
#include "noCar.h"


NoCar::NoCar()
{
	_name = "defoltName";
	_coord[0] = 5.1111;
	_coord[1] = 5.1111;
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

void NoCar::setCoord(float coordAdd[]) {
	_coord[0] = coordAdd[0];
	_coord[1] = coordAdd[1];
}

NoCar::~NoCar()
{
}
