#include "checkup.h"

string enterEng(istream& in, string enterMsg) {
	char errorMsg[] = { "Ошибка ввода. Пользуйтесь латиницей\0" };
	bool fl;
	string str;

	do {
		try {
			fl = false;
			cout << enterMsg;
			rewind(stdin);
			getline(in, str);

			for (int i = 0; i < str.length(); i++) {
				if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') && str[i] != ' ') {
					throw exp_vvod(50, errorMsg);
				}
			}
		}
		catch (exp_vvod obj) {
			cout << endl;
			obj.show();
			rewind(stdin);
			fl = true;
		}
		catch (...) {
			cout << endl;
			cout << "Неверный ввод\n";
			rewind(stdin);
			fl = true;
		}
	} while (fl);

	string ret(str);
	return ret;
}
string enterRus(istream& in, string enterMsg) {
	char errorMsg[] = { "Ошибка ввода. Пользуйтесь кириллицей\0" };
	bool fl;
	string str;

	do {
		try {
			fl = false;
			cout << enterMsg;
			rewind(stdin);
			getline(in, str);

			for (int i = 0; i < str.size(); i++) {
				if ((str[i] < 'А' || str[i] > 'Я') && (str[i] < 'а' || str[i] > 'я')) {
					throw exp_vvod(51, errorMsg);
				}
			}
		}
		catch (exp_vvod obj) {
			cout << endl;
			obj.show();
			rewind(stdin);
			fl = true;
		}
		catch (...) {
			cout << endl;
			cout << "Неверный ввод\n";
			rewind(stdin);
			fl = true;
		}

	} while (fl);

	string ret(str);
	return ret;
}
string enterDate(istream& in) {
	cout << "Введите дату производства:" << endl;
	return to_string(enterInt(in, "год", 1950, 2022)) + '.'
		+ to_string(enterInt(in, "месяц", 1, 12)) + '.'
		+ to_string(enterInt(in, "день", 1, 31));
}
string enterModel(istream& in) {
	char errorMsg[] = { "Ошибка ввода. Все буквы должны быть латинскими и заглавными\0" };
	bool flag;
	char* str;
	str = new char[80];

	do {
		try {
			flag = false;
			cout << "Введите модель, используя цифры и заглавные латинскими буквами : ";
			in >> str;

			for (int i = 0; i < strlen(str); i++) {
				if ((str[i] < 'A' || str[i] > 'Z') && (str[i]<'0' || str[i]>'9')) {
					throw exp_vvod(53, errorMsg);
				}
			}
		}
		catch (exp_vvod obj) {
			cout << endl;
			obj.show();
			rewind(stdin);
			flag = true;
		}
		catch (...) {
			cout << endl;
			cout << "Неверный ввод\n";
			rewind(stdin);
			flag = true;
		}
	} while (flag);

	string ret(str);
	return ret;
}
bool enterOrig(istream& in) {
	char errorMsg[] = { "Ошибка ввода. Введите \"Y\"/\"N\"\0" };
	bool flag;
	char str;

	do {
		try {
			flag = false;
			cout << "Оригинал(\"Y\"/\"N\") : ";
			in >> str;

			if (str != 'N' && str != 'Y')
			throw exp_vvod(54, errorMsg);
			
			
		}
		catch (exp_vvod obj) {
			cout << endl;
			obj.show();
			rewind(stdin);
			flag = true;
		}
		catch (...) {
			cout << endl;
			cout << "Неверный ввод\n";
			rewind(stdin);
			flag = true;
		}
	} while (flag);

	if (str == 'Y')
		return true;
	else
		return false;
}

double enterDouble(istream& in, string enterMsg, int min, int max) {
	double num;
	char errorSim[] = { "Ошибка ввода. Ввод букв недопустим\0" };
	char errorLim[] = { "ошибка ввода. Выход за пределы допустимых значений\0" };
	bool flag;

	do {
		try
		{
			flag = 0;
			cout << enterMsg << " от " << min << " до " << max << " : ";
			in >> num;
			if(!in.good() || in.peek() != '\n')
				throw exp_vvod(60, errorSim);
			else if (num < min || num > max) {
				throw exp_vvod(60, errorLim);
			}
		}
		catch (exp_vvod obj)
		{
			cout << endl;
			flag = 1;
			obj.show();
			in.clear();
			rewind(stdin);
		}
		catch (...) {
			cout << endl;
			cout << "Неверный ввод\n";
			rewind(stdin);
			flag = true;
		}
	} while (flag);

	return num;
}
int enterInt(istream& in, string enterMsg, int min, int max) {
	int num;
	char errorSim[] = { "Ошибка ввода. Ввод букв недопустим\0" };
	char errorLim[] = { "ошибка ввода. Выход за пределы допустимых значений\0" };
	bool flag;

	do {
		try
		{
			flag = 0;
			cout << enterMsg << " от " << min << " до " << max  << " : ";
			in >> num;
			if (!in.good() || in.peek() != '\n')
				throw exp_vvod(60, errorSim);
			if (num < min || num > max) {
				throw exp_vvod(60, errorLim);
			}
		}
		catch (exp_vvod obj)
		{
			cout << endl;
			flag = 1;
			obj.show();
			in.clear();
			rewind(stdin);
		}
		catch (...) {
			cout << endl;
			cout << "Неверный ввод\n";
			rewind(stdin);
			flag = true;
		}
	} while (flag);

	return num;
}
double enterDouble(istream& in, string enterMsg) {
	double num;
	char errorSim[] = { "Ошибка ввода. Ввод букв недопустим\0" };
	bool flag;

	do {
		try
		{
			flag = 0;
			cout << enterMsg;
			in >> num;
			if (!in.good() || in.peek() != '\n')
				throw exp_vvod(60, errorSim);
		}
		catch (exp_vvod obj)
		{
			cout << endl;
			flag = 1;
			obj.show();
			in.clear();
			rewind(stdin);
		}
		catch (...) {
			cout << endl;
			cout << "Неверный ввод\n";
			rewind(stdin);
			flag = true;
		}
	} while (flag);

	return num;
}
int enterInt(istream& in, string enterMsg) {
	int num;
	char errorSim[] = { "Ошибка ввода. Ввод букв недопустим\0" };
	bool flag;

	do {
		try
		{
			flag = 0;
			cout << enterMsg;
			in >> num;
			if (!in.good() || in.peek() != '\n')
				throw exp_vvod(60, errorSim);
		}
		catch (exp_vvod obj)
		{
			cout << endl;
			flag = 1;
			obj.show();
			in.clear();
			rewind(stdin);
		}
		catch (...) {
			cout << endl;
			cout << "Неверный ввод\n";
			rewind(stdin);
			flag = true;
		}
	} while (flag);

	return num;
}

bool fileOpening(ifstream& fin) {
	char errorMsg[] = {"Не удалось найти файл\0"};
	try {
		if (fin.is_open()) {
			//проверка на то, пуст ли файл
			fin.seekg(0, std::ios_base::end);
			if (fin.tellg() > 0) {
				return 1;
			}
			else {
				cout << "файл пустой\n" << endl;
				return 0;
			}
		}
		else
			throw exp_vvod(70, errorMsg);
	}
	catch (exp_vvod obj) {
		cout << endl;
		obj.show();
		return 0;
	}
	catch (...) {
		cout << endl;
		cout << "Не удалось найти файл\n";
		return 0;
	}
}