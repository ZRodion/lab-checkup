#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "exp_vvod.h"
#include "checkup.h"

using namespace std;

class Watch {
protected:
	double price;
	string date;
	string name;
	string model;
	bool original;
public:
	Watch(double price, string date, string name, string model, bool original) {
		this->price = price;
		this->date = date;
		this->name = name;
		this->model = model;
		this->original = original;
	}
	Watch() { }

	void setModel(string);
	string setModel() const;

	void setOriginal(bool);
	bool getOriginal() const;

	void setPrice(double);
	double getPrice() const;

	void setDate(string);
	string  getDate() const;
	
	void setName(string);
	string getName() const;

	static string replace(string);
	static void space(string&);
	virtual void preEditing();

	friend ostream& operator <<(ostream&, Watch&);
	friend istream& operator >>(istream&, Watch&);

	friend ofstream& operator<<(ofstream&, const Watch&);
	friend ifstream& operator>>(ifstream&, Watch&);
};