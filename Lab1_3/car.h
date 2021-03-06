
#pragma once

#include <cmath>   
#include <QString>
#include "noCar.h"
class Car:
	public NoCar
{
public:
	Car();
	Car(QString nameAdd, float angleAdd,float sizeAdd[], float coordAdd[]);
	Car(const Car &car);
	Car(const NoCar &car);
	virtual ~Car();

	void copyCar(const Car &car);
	
	float getAngle() const override;
	float getSize(int i) const override;
	UnitCar getType() const override { return ca; };
	float getA(int i) const override;
	float getB(int i) const override;
	float getC(int i) const override;
	float getD(int i) const override;
	//float getDots() const;
	float getRBig() const override;
	void setAngle(float angleAdd) ;
	void setSize(float sizeAdd[]) ;
	Car& operator = (NoCar t);
	
	float getR() const override;
	//void calculate();
private:
	
	float _size[2], _angle;
	float _O[2];
};

