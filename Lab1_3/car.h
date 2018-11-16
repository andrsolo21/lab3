
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
	~Car();

	void copyCar(const Car &car);
	
	float getAngle() const override;
	float getSize(int i) const override;
	bool getType() const override { return true; };
	float getA(int i) const override;
	float getB(int i) const override;
	float getC(int i) const override;
	float getD(int i) const override;
	//float getDots() const;
	float getRBig() const override;
	void setAngle(float angleAdd) ;
	void setSize(float sizeAdd[]) ;
	Car& operator = (NoCar t);
	

	void calculate();
private:
	
	float _size[2], _angle;
	float _A[2], _B[2], _C[2], _D[2], _O[2],_R,_dots[4][2];
};

