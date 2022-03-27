#pragma once
#include "Watch.h"

class Wristwatch : public Watch
{
protected:
	string strap;
	string shape;
public:
	Wristwatch(double price, string date, string name, string strap, string shape, string model, bool original) :
		Watch(price, date, name, model, original)
	{
		this->strap = strap;
		this->shape = shape;
	}
	Wristwatch() {}

	void setStrap(string);
	void setShape(string);

	string getStrap() const;
	string getShape() const;

	void preEditing() override;

	friend ostream& operator <<(ostream&, Wristwatch&);
	friend istream& operator >> (istream&, Wristwatch&);
};
