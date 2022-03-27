#include <iostream>
#include <Windows.h>
#include "Interface.h"
#include "Hourglass.h"
#include "Mechanical_wristwatch.h"
#include "Smart_watch.h"
#include "Fitness_bracelet.h"
#include "Watch.h"

using namespace std;

int main()
{
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	IStack<int> a;
	a.menuType();

	return 0;
}