#include "Mechanical_wristwatch.h"

void Mechanical_wristwatch::setBody_material(string body_material) {
	this->body_material = body_material;
}

string Mechanical_wristwatch::getBody_material() const
{
	return body_material;
}

void Mechanical_wristwatch::header() {
	cout << "------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|" << setw(124) << " Механические наручные часы                                       " << "|\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "№ " << "|" << setw(15) << " Название  " << "|" << setw(10) << " Цена";
	cout << "|" << setw(15) << "Дата производства";
	cout << "|" << setw(12) << "Оригинал" << "|" << setw(10) << "модель" << "|";
	cout << setw(16) << "Материал ремешка";
	cout << "|" << setw(16) << "Форма циферблата" << "|" << setw(19) << "Материал циферблата" << "|\n";
	cout << "------------------------------------------------------------------------------------------------------------------------------\n";
}
void Mechanical_wristwatch::searchHeader() {
	cout << "------------------------------------------------------------------------------------------------------\n";
	cout << " |" << setw(15) << " Название  " << "|" << setw(10) << " Цена";
	cout << "|" << setw(15) << "Дата производства" << "|" << setw(16) << "Материал ремешка";
	cout << "|" << setw(16) << "Форма циферблата" << "|" << setw(19) << "Материал циферблата" << "|\n";
	cout << "------------------------------------------------------------------------------------------------------\n";
}

void Mechanical_wristwatch::preEditing() {
	Wristwatch::preEditing();
	cout << "6 - материал ремешка\n";
}
void Mechanical_wristwatch::editing() {
	int num, choice;
	string str;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cin >> str;
		setName(str);
		break;
	case 2:
		cin >> num;
		setPrice(num);
		break;
	case 3:
		cin >> str;
		setDate(str);
		break;
	case 4:
		cin >> str;
		setShape(str);
		break;
	case 5:
		cin >> str;
		setStrap(str);
		break;
	case 6:
		cin >> str;
		setBody_material(str);
		break;
	default: cout << "Ошибка. Пункта меню не существует.\n";
		break;
	}
}

ostream& operator <<(ostream& out, Mechanical_wristwatch& mw) {
	out << dynamic_cast<Wristwatch&>(mw);
	out << setw(19) << mw.body_material;
	out << "|\n";
	out << "------------------------------------------------------------------------------------------------------------------------------";
	return out;
}
istream& operator >> (istream& in, Mechanical_wristwatch& mw) {
	in >> dynamic_cast<Wristwatch&>(mw);
	cout << endl;
	mw.body_material = enterRus(in, "Введите материал циферблата на кириллице: ");
	return in;
}

ofstream& operator <<(ofstream& out, Mechanical_wristwatch& mw) {
	out << Watch::replace(mw.name) << " ";
	out << mw.price << " ";
	out << mw.date << " ";
	out << mw.original << " ";
	out << mw.model << " ";
	out << mw.shape << " ";
	out << mw.strap << " ";
	out << mw.body_material;
	return out;
}
ifstream& operator >> (ifstream& in, Mechanical_wristwatch& mw) {
	in >> mw.name;
	Watch::space(mw.name);
	in >> mw.price;
	in >> mw.date;
	in >> mw.original;
	in >> mw.model;
	in >> mw.shape;
	in >> mw.strap;
	in >> mw.body_material;
	return in;
}
