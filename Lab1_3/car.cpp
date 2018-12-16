#include "stdafx.h"
#include "car.h"
//#include <cstring>
//#include <iostream>
//#include <cstdio>
using namespace std;

Car::Car()
{
	//_kind = ukCar;
	_name = "newCar";
	_angle = 0;
	_size[0] = 1.5;
	_size[1] = 3;
	_coord[0] = 1;
	_coord[1] = 1;
}
Car::Car(QString nameAdd, float angleAdd, float sizeAdd[], float coordAdd[]) {
	if (nameAdd != "")
		_name = nameAdd;
	else {
		_name = "newCar";
	}
	int toAngle = int(angleAdd);
	_angle = (toAngle % 360 + 360) % 360 + angleAdd - toAngle;
	if (sizeAdd[0] > 0)
		_size[0] = sizeAdd[0];
	else {
		_size[0] = 1.5;
	}
	if (sizeAdd[1] > 0)
		_size[1] = sizeAdd[1];
	else {
		_size[1] = 3;
	}
	_coord[0] = coordAdd[0];
	_coord[1] = coordAdd[1];
	//calculate();
}
Car::Car(const Car &car) {
	_name = car.getName();
	_angle = car.getAngle();
	_size[0] = car.getSize(0);
	_size[1] = car.getSize(1);
	_coord[0] = car.getCoord(0);
	_coord[1] = car.getCoord(1);
	//calculate();

}
Car::Car(const NoCar &car) {
	if (car.getType() == ca) {
		_name = car.getName();
		_angle = car.getAngle();
		_size[0] = car.getSize(0);
		_size[1] = car.getSize(1);
		_coord[0] = car.getCoord(0);
		_coord[1] = car.getCoord(1);
	}
	//calculate();

}
Car& Car::operator = (NoCar car) {
	_name = car.getName();
	_angle = car.getAngle();
	_size[0] = car.getSize(0);
	_size[1] = car.getSize(1);
	_coord[0] = car.getCoord(0);
	_coord[1] = car.getCoord(1);
	//calculate();
	return *this;
}
void Car::copyCar(const Car &car) {
	_name = car.getName();
	_angle = car.getAngle();
	_size[0] = car.getSize(0);
	_size[1] = car.getSize(1);
	_coord[0] = car.getCoord(0);
	_coord[1] = car.getCoord(1);
	//calculate();
}
void Car::setAngle(float angleAdd) {
	int toAngle = int(angleAdd);
	_angle = (toAngle % 360 + 360) % 360 + angleAdd - toAngle;
}
void Car::setSize(float sizeAdd[]) {
	if (sizeAdd[0] > 0 && sizeAdd[1] > 0) {
		_size[0] = sizeAdd[0];
		_size[1] = sizeAdd[1];
	}
}
float Car::getAngle() const {
	return _angle;
}
float Car::getSize(int i) const {
	return _size[i % 2];
}
float Car::getA(int i) const {
	return getRBig() * sin(-1 * atan(_size[1] / _size[0])) + _coord[i%2];
}
float Car::getB(int i) const {
	return  getRBig() * sin(atan(_size[1] / _size[0]) - 90) + _coord[i%2];
}
float Car::getC(int i) const {
	return getRBig() * sin(atan(_size[1] / _size[0])) + _coord[i%2];
}
float Car::getD(int i) const {
	return getRBig() * sin(90 + atan(_size[1] / _size[0])) + _coord[i%2];
}
float Car::getRBig() const {
	return sqrt(((_size[0]) / 2) * ((_size[0]) / 2) + ((_size[1]) / 2) * ((_size[1]) / 2));
}

/*void Car::calculate() {

	_C[0] = 
	_D[0] = _R * sin(90 + fi) + _coord[0];
	_A[0] = _R * sin(-1 * fi) + _coord[0];
	_B[0] = _R * sin(fi - 90) + _coord[0];

	_C[1] = _R * cos(fi) + _coord[1];
	_D[1] = _R * cos(90 + fi) + _coord[1];
	_A[1] = _R * cos(-1 * fi) + _coord[1];
	_B[1] = _R * cos(fi - 90) + _coord[1];
}*/
float Car::getR() const {
	if (_size[0] / 2 > _size[1] / 2)
		return _size[1] / 2;
	else
		return _size[0] / 2;
}

Car::~Car()
{

}