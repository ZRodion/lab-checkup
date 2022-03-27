#pragma once
#include "Wristwatch.h";

class Digital_watch : public Wristwatch
{
protected:
	int battery;
public:
	Digital_watch(double price, string date, string name, string clasp, string shape, int battery, string model, bool original) :
		Wristwatch(price, date, name, clasp, shape, model, original)
	{
		this->battery = battery;
	}
	Digital_watch() {}

	void setBattery(int);
	int getBattey() const;

	void preEditing() override;

	friend ostream& operator <<(ostream&, Digital_watch&);
	friend istream& operator >> (istream&, Digital_watch&);
};