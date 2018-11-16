#pragma once
#include "Car.h"
#include "noCar.h"
#include <fstream> 
#include <string>
#include <QString>
#include <iostream>
using namespace std;

class MotorShow
{

public:
	MotorShow();
	//MotorShow(Car * addData[], int addCount, float addGabarits[]);
	MotorShow(const MotorShow & addData);
	MotorShow(std::string f);
	~MotorShow();
	void deleteAll();

	int getCount() const;
	void addEl(NoCar * element);
	void addEl(Car * element);
	void deleteElement(int i);

	NoCar ** operator[](int c) const;
	float getGabarits(int i) const;

protected:
	NoCar **_head, **_tail;
	int _grr = 0;

	void grow10(int zn = 1);
	bool checkCar(const NoCar & carToCheck);
	bool checkP(const NoCar & pToCheck);
	bool checkEl(const NoCar & elToCheck);

	float linear(float x[2], float a[2], float b[2]);
	int countDots(float a[2], float b[2], float rec[][2]);
	bool dots(float dots1[][2], float dots2[][2]);
	bool checkGabarits(float dots1[][2]);

	float _gabarits[2];

};

