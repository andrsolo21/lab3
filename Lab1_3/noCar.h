#pragma once
//enum UnitCar = { ukCar,ukCircle };

class NoCar
{
public:
	NoCar();
	NoCar(const NoCar &addNo);
	NoCar(QString nameAdd, float rAdd, float coordAdd[]);
	~NoCar();
	QString getName() const;
	float getCoord(int i) const;
	void setName(QString nameAdd);	
	void setCoord(float coordAdd[]);
	virtual bool isCar() const;
	float getR() const;
	virtual bool getType() const { return false; }

	//UnitCar getKind() { return _kind; };

	virtual float getAngle() const {}
	virtual float getSize(int i) const {}
	virtual float getA(int i) const{}
	virtual float getB(int i) const {}
	virtual float getC(int i) const {}
	virtual float getD(int i) const {}
	virtual float getRBig() const {}

protected:
	QString _name;
	float _coord[2], _r;

};

