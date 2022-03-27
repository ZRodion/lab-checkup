#include "Hourglass.h"

void Hourglass::setMeasured_time(int measured_time) {
	this->measured_time = measured_time;
}

int Hourglass::getMeasured_time() {
	return measured_time;
}
void Hourglass::header() {
	cout << "---------------------------------------------------------------------------------------------\n";
	cout << "|" << setw(91) << " �������� ����                                     " << "|\n";
	cout << "---------------------------------------------------------------------------------------------\n";
	cout << "� " << "|" << setw(15) << " ��������  " << "|" << setw(10) << " ����";
	cout << "|" << setw(15) << "���� ������������" << "|" << setw(12) << "��������" << "|" << setw(10) << "������" << "|" <<setw(20) << "������������� �����" << "|\n";
	cout << "---------------------------------------------------------------------------------------------\n";
}

void Hourglass::searchHeader() {
	cout << "---------------------------------------------------------------------\n";
	cout << " |" << setw(15) << " ��������  " << "|" << setw(10) << " ����";
	cout << "|" << setw(15) << "���� ������������" << "|" << setw(20) << "������������� �����" << "|\n";
	cout << "---------------------------------------------------------------------\n";
}

void Hourglass::preEditing() {
	Watch::preEditing();
	cout << "4 - ������������� �����\n";
}
void Hourglass::editing() {
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
		cin >> num;
		setMeasured_time(num);
		break;
	default: cout << "������. ������ ���� �� ����������.\n";
		break;
	}
}

ostream& operator <<(ostream& out, Hourglass& hg) {
	out << dynamic_cast<Watch&>(hg);
	out << setw(20) << hg.measured_time;
	out << "|\n";
	out << "-------------------------------------------------------------------------------------------- - ";
	return out;
}
istream& operator >> (istream& in, Hourglass& hg) {
	in >> dynamic_cast<Watch&>(hg);
	hg.measured_time = enterInt(in, "������� ������������� ����� : ");
	return in;
}

ofstream& operator <<(ofstream& out, Hourglass& hg) {
	out << Watch::replace(hg.name) << " ";
	out << hg.price << " ";
	out << hg.date << " ";
	out << hg.original << " ";
	out << hg.model << " ";
	out << hg.measured_time;
	return out;
}
ifstream& operator >> (ifstream& in, Hourglass& hg) {
	in >> hg.name;
	Watch::space(hg.name);
	in >> hg.price;
	in >> hg.date;
	in >> hg.original;
	in >> hg.model;
	in >> hg.measured_time;
	return in;
}
