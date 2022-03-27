#pragma once
#include "Watch.h"

class Hourglass : public Watch
{
	int measured_time;
public:
	Hourglass(double price, string date, string name, int measured_time, string model, bool original) : Watch(price, date, name, model, original)
	{
		this->measured_time = measured_time;
	}
	Hourglass() { }

	void setMeasured_time(int);

	int getMeasured_time();

	void searchHeader();
	void header();

	void preEditing() override;
	void editing();

	friend ostream& operator <<(ostream&, Hourglass&);
	friend istream& operator >> (istream&, Hourglass&);

	friend ofstream& operator <<(ofstream&, Hourglass&);
	friend ifstream& operator >> (ifstream&, Hourglass&);
};