#pragma once
#include <string>
#include <fstream>
#include <limits>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include "exp_vvod.h"

using namespace std;

//проверка на ввод строки
string enterEng(istream& in, string);
string enterRus(istream& in, string);
string enterDate(istream& in);
string enterModel(istream& in);
bool enterOrig(istream& in);

//проверка на ввод числа
double enterDouble(istream& in, string, int min, int max);
int enterInt(istream& in, string, int min, int max);
double enterDouble(istream& in, string);
int enterInt(istream& in, string);

bool fileOpening(ifstream& fin);