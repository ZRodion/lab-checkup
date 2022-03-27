#pragma once
#include <windows.h>
#include "exp.h"

class exp_vvod : public exp
{
	char message[80];
public:
	exp_vvod(int code, char* str):exp(code) {
		strcpy_s(message, str);
	}
	~exp_vvod() {};
	void show() {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
		cout <<code << " : " << message << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	}
};
