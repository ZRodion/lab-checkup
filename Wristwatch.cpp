#include "Wristwatch.h"

void Wristwatch::setStrap(string strap) {
	this->strap = strap;
}
void Wristwatch::setShape(string shape) {
	this->shape = shape;
}

string Wristwatch::getStrap() const
{
	return strap;
}
string Wristwatch::getShape() const
{
	return shape;
}

void Wristwatch::preEditing() {
	Watch::preEditing();
	cout << "4 - материал ремешка\n5 - форма корпуса\n";
}

ostream& operator <<(ostream& out, Wristwatch& wr) {
	out << dynamic_cast<Watch&>(wr);
	out << setw(16) << wr.strap;
	out << "|";
	out << setw(16) << wr.shape;
	out << "|";
	return out;
}
istream& operator >> (istream& in, Wristwatch& wr) {
	in >> dynamic_cast<Watch&>(wr);
	cout << endl;
	wr.strap = enterRus(in, "¬ведите материал ремешка на кириллице: ");
	cout << endl;
	wr.shape = enterRus(in, "¬ведите форму циферблата на кириллице: ");
	return in;
}