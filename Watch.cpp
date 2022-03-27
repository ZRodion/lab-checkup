#include "Watch.h"

void Watch::setPrice(double price) {
	this->price = price;
}
void Watch::setDate(string date) {
	this->date = date;
}
void Watch::setName(string name) {
	this->name = name;
}
string Watch::getName() const
{
	return name;
}
double Watch::getPrice() const
{
	return price;
}
string Watch::getDate() const
{
	return date;
}
string Watch::replace(string str) {
	int length = str.size();
	int x = 0;
	string fixed;

	while (x != length) {
		string letter = str.substr(x, 1);
		if (letter == " ") {
			letter = "_";
		}
		fixed = fixed + letter;
		x = x + 1;
	}

	return fixed;
}
void Watch::space(string& str) {
	int length = str.size();
	int x = 0;
	string fixed;

	while (x != length) {
		string letter = str.substr(x, 1);
		if (letter == "_") {
			letter = " ";
		}
		fixed = fixed + letter;
		x = x + 1;
	}
	str = fixed;
}

void Watch::preEditing() {
	cout << "1 - название\n2 - цена\n3 - дата производства\n";
}
ostream& operator <<(ostream& out, Watch& watch) {
	out << " |";
	out << setw(15) << watch.name;
	out << "|";
	out << setw(10) << watch.price;
	out << "|";
	out << setw(17) << watch.date;
	out << "|";
	if(watch.original = 1)
		out << setw(12) << "Да";
	else
		out << setw(12) << "Нет";
	out << "|";
	out << setw(10) << watch.model;
	out << "|";
	return out;
}
istream& operator >> (istream& in, Watch& watch) {
	watch.name = enterEng(in, "Введите название часов на латинице : ");
	cout << endl;
	watch.price = enterDouble(in, "Введите цену : ");
	cout << endl;
	watch.date = enterDate(in);
	cout << endl;
	watch.model = enterModel(in);
	cout << endl;
	watch.original = enterOrig(in);

	return in;
}

//в файл
ofstream& operator <<(ofstream& out, const Watch& watch) {
	out << Watch::replace(watch.name) << " ";
	out << watch.price << " ";
	out << watch.date << " ";
	out << watch.original << " ";
	out << watch.model << " ";
	return out;
}
//из файла
ifstream& operator>>(ifstream& in, Watch& watch) {
	in >> watch.name;
	in >> watch.price;
	in >> watch.date;
	in >> watch.original;
	in >> watch.model;
	Watch::space(watch.name);

	return in;
}
