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
	float getR() const;
	virtual bool getType() const { return false; }

	//UnitCar getKind() { return _kind; };

	virtual float getAngle() const { return 0; };
	virtual float getSize(int i) const { return 0; };
	virtual float getA(int i) const { return 0; };
	virtual float getB(int i) const { return 0; };
	virtual float getC(int i) const { return 0; };
	virtual float getD(int i) const { return 0; };
	virtual float getRBig() const { return 0; };

protected:
	QString _name;
	float _coord[2], _r;

};
Q_DECLARE_METATYPE(NoCar*)

