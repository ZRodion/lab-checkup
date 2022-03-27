#include "Smart_watch.h"

void Smart_watch::setNavigation(string navigation) {
	this->navigation = navigation;
}
string Smart_watch::getNavigation() const
{
	return navigation;
}

void Smart_watch::header() {
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|" << setw(135) << " ����� ����                                                                 " << "|\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "� " << "|" << setw(15) << " ��������  " << "|" << setw(10) << " ����";
	cout << "|" << setw(15) << "���� ������������" << "|";
	cout << setw(12) << "��������" << "|" << setw(10) << "������"; 
	cout << "|" << setw(16) << "�������� �������";
	cout << "|" << setw(16) << "����� ����������";
	cout << "|" << setw(15) << "������� �������" << "|" << setw(14) << "��� ���������" << "|\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------\n";
}
void Smart_watch::searchHeader() {
	cout << "-----------------------------------------------------------------------------------------------------------------\n";
	cout << " |" << setw(15) << " ��������  " << "|" << setw(10) << " ����";
	cout << "|" << setw(15) << "���� ������������" << "|" << setw(16) << "�������� �������";
	cout << "|" << setw(16) << "����� ����������";
	cout << "|" << setw(15) << "������� �������" << "|" << setw(14) << "��� ���������" << "|\n";
	cout << "-----------------------------------------------------------------------------------------------------------------\n";
}
void Smart_watch::preEditing() {
	Digital_watch::preEditing();
	cout << "7 - ���������\n";
}
void Smart_watch::editing() {
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
		cin >> num;
		setBattery(num);
		break;
	case 7:
		cin >> str;
		setNavigation(str);
		break;
	default: cout << "������. ������ ���� �� ����������.\n";
		break;
	}
}

ostream& operator << (ostream& out, Smart_watch& sw) {
	out << dynamic_cast<Digital_watch&>(sw);
	out << setw(14) << sw.navigation;
	out << "|\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------";
	return out;
}

istream& operator >> (istream& in, Smart_watch& sw) {
	in >> dynamic_cast<Digital_watch&>(sw);
	cout << endl;
	sw.navigation = enterEng(in, "������� ��� ��������� �� ��������: ");;
	return in;
}

ofstream& operator <<(ofstream& out, Smart_watch& sw) {
	out << Watch::replace(sw.name) << " ";
	out << sw.price << " ";
	out << sw.date << " ";
	out << sw.original << " ";
	out << sw.model << " ";
	out << sw.shape << " ";
	out << sw.strap << " ";
	out << sw.battery << " ";
	out << sw.navigation;

	return out;
}
ifstream& operator >>(ifstream& in, Smart_watch& sw) {
	in >> sw.name;
	Watch::space(sw.name);
	in >> sw.price;
	in >> sw.date;
	in >> sw.original;
	in >> sw.model;
	in >> sw.shape;
	in >> sw.strap;
	in >> sw.battery;
	in >> sw.navigation;
	return in;
}