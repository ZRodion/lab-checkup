#pragma once
#include "Digital_watch.h";

class Fitness_bracelet : public Digital_watch
{
	int number_of_workouts;
public:
	Fitness_bracelet(double price, string date, string name, string strap, string shape, int battery, int number_of_workouts, string model, bool original) :
		Digital_watch(price, date, name, strap, shape, battery, model, original)
	{
		this->number_of_workouts = number_of_workouts;
	}
	Fitness_bracelet() { }

	void setNumber_of_workouts(int);
	int getNumber_of_workouts() const;

	static void searchHeader();
	static void header();

	void preEditing() override;
	void editing();

	friend ostream& operator <<(ostream&, Fitness_bracelet&);
	friend istream& operator >>(istream&, Fitness_bracelet&);

	friend ofstream& operator <<(ofstream&, Fitness_bracelet&);
	friend ifstream& operator >>(ifstream&, Fitness_bracelet&);
};