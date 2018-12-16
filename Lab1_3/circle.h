#pragma once
#include "noCar.h"
#include <QString>
class Circle:
	public NoCar
{
public:
	Circle();
	Circle(const Circle &addNo);
	Circle(QString nameAdd, float rAdd, float coordAdd[]);
	Circle& operator = (NoCar car);
	virtual ~Circle();
	virtual float getR() const override { return _r; };
	void setR(float r) {
		if (r > 0) {
			_r = r;
		}
	}
	UnitCar getType() const override { return ci; };

private:
	float  _r;
};

