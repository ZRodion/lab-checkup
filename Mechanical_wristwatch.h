#pragma once
#include "Wristwatch.h";

class Mechanical_wristwatch : public Wristwatch
{
	string body_material;
public:
	Mechanical_wristwatch(double price, string date, string name, string strap, string shape, string body_material, string model, bool original) :
		Wristwatch(price, date, name, strap, shape, model, original)
	{
		this->body_material = body_material;
	}
	Mechanical_wristwatch() {}

	void setBody_material(string);
	string getBody_material() const;

	static void searchHeader();
	static void header();

	void preEditing() override;
	void editing();

	friend ostream& operator <<(ostream&, Mechanical_wristwatch&);
	friend istream& operator >> (istream&, Mechanical_wristwatch&);

	friend ofstream& operator <<(ofstream&, Mechanical_wristwatch&);
	friend ifstream& operator >> (ifstream&, Mechanical_wristwatch&);
};