#include "Digital_watch.h"

void Digital_watch::setBattery(int battery) {
	this->battery = battery;
}
int Digital_watch::getBattey() const
{
	return battery;
}

void Digital_watch::preEditing() {
	Wristwatch::preEditing();
	cout << "6 - ������� �������\n";
}

ostream& operator <<(ostream& out, Digital_watch& dw) {
	out << dynamic_cast<Wristwatch&>(dw);
	out << setw(15) << dw.battery;
	out << "|";
	return out;
}
istream& operator >> (istream& in, Digital_watch& dw) {
	in >> dynamic_cast<Wristwatch&>(dw);
	cout << endl;
	dw.battery = enterInt(in, "������� ������� �������", 1000, 5000);
	return in;
}