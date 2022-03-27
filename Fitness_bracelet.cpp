#include "Fitness_bracelet.h"

void Fitness_bracelet::setNumber_of_workouts(int number_of_workouts) {
	this->number_of_workouts = number_of_workouts;
}
int Fitness_bracelet::getNumber_of_workouts() const
{
	return number_of_workouts;
}

void Fitness_bracelet::header() {
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "|" << setw(150) << " ������ �������                                                                 " << "|\n";
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "� " << "|" << setw(15) << " ��������  " << "|" << setw(10) << " ����";
	cout << "|" << setw(15) << "���� ������������";
	cout << "|" << setw(12) << "��������" << "|" << setw(10) << "������";
	cout << "|" << setw(16) << "�������� �������";
	cout << "|" << setw(16) << "����� ����������";
	cout << "|" << setw(15) << "������� �������" << "|" << setw(29) << "���������� ������� ����������" << "|\n";
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}
void Fitness_bracelet::searchHeader() {
	cout << "--------------------------------------------------------------------------------------------------------------------------------\n";
	cout << " |" << setw(15) << " ��������  " << "|" << setw(10) << " ����";
	cout << "|" << setw(15) << "���� ������������" << "|" << setw(16) << "�������� �������";
	cout << "|" << setw(16) << "����� ����������";
	cout << "|" << setw(15) << "������� �������" << "|" << setw(29) << "���������� ������� ����������" << "|\n";
	cout << "--------------------------------------------------------------------------------------------------------------------------------\n";
}

void Fitness_bracelet::preEditing() {
	Digital_watch::preEditing();
	cout << "7 - ���������� ����������\n";
}
void Fitness_bracelet::editing() {
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
		cin >> num;
		setNumber_of_workouts(num);
		break;
	default: cout << "������. ������ ���� �� ����������.\n";
		break;
	}
}

ostream& operator <<(ostream& out, Fitness_bracelet& fb) {
	out << dynamic_cast<Digital_watch&>(fb);
	out << setw(29) << fb.number_of_workouts;
	out << "|\n";
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------";

	return out;
}
istream& operator >> (istream& in, Fitness_bracelet& fb) {
	in >> dynamic_cast<Digital_watch&>(fb);
	cout << endl;
	fb.number_of_workouts = enterInt(in, "������� ���������� ����������(�� 0 �� 100)", 0, 100);
	return in;
}

ofstream& operator <<(ofstream& out, Fitness_bracelet& fb) {
	out << Watch::replace(fb.name) << " ";
	out << fb.price << " ";
	out << fb.date << " ";
	out << fb.original << " ";
	out << fb.model << " ";
	out << fb.shape << " ";
	out << fb.strap << " ";
	out << fb.battery << " ";
	out << fb.number_of_workouts;

	return out;
}
ifstream& operator >>(ifstream& in, Fitness_bracelet& fb) {
	in >> fb.name;
	Watch::space(fb.name);
	in >> fb.price;
	in >> fb.date;
	in >> fb.original;
	in >> fb.model;
	in >> fb.shape;
	in >> fb.strap;
	in >> fb.battery;
	in >> fb.number_of_workouts;
	return in;
}