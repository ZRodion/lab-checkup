#pragma once
#include "Digital_watch.h"

class Smart_watch : public Digital_watch
{
	string navigation;
public:
	Smart_watch(double price, string date, string name, string strap, string shape, int battery, string navigation, string model, bool original) :
		Digital_watch(price, date, name, strap, shape, battery, model, original)
	{
		this->navigation = navigation;
	}
	Smart_watch() { }

	void setNavigation(string);
	string getNavigation() const;

	static void searchHeader();
	static void header();

	void preEditing() override;
	void editing();

	friend ostream& operator <<(ostream&, Smart_watch&);
	friend istream& operator >>(istream&, Smart_watch&);

	friend ofstream& operator <<(ofstream&, Smart_watch&);
	friend ifstream& operator >>(ifstream&, Smart_watch&);
};