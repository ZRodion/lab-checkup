#pragma once
#include <Windows.h>
#include <iostream>
#include "Stack.h"
#include "Hourglass.h"
#include "Mechanical_wristwatch.h"
#include "Smart_watch.h"
#include "Fitness_bracelet.h"
#include "Watch.h"
#include "txtFiles.h"

//#include <fstream>
//#include "All.h"
//#include "exp_vvod.h"
//#include "Stack.h" 

const string FILE_FOR_HOURGLASS = "Hourglass.txt";
const string FILE_FOR_MECHANICAL_WRISTWATCH = "Mechanical_wristwatch.txt";
const string FILE_FOR_SMART_WATCH = "Smart_watch.txt";
const string FILE_FOR_FITNESS_BRACELET = "Fitness_bracelet.txt";


template <class T>
class IStack
{
public:
	IStack() {}
	void menuType();
	static void menuFun(string);
};

template<class T>
void IStack<T>::menuFun(string type)
{
	txtFile<T> file(type);
	Stack<T> s;
	file.readFile(s);
	T value;
	T* link;

	int choice, ind, num;

	while (true)
	{
		cout << "1 - ��������\n2 - ����������\n3 - �������� �������\n4 - �������� ����\n5 - ���������� ������� � �����\n6 - ����� �� �������\n7 - �������� �� �������\n8 - ��������������\n9 - �����\n" << endl;
		cin >> choice;
	
		switch (choice)
		{
		case 1:
			system("cls");
			s.show();
			break;
		case 2:
			system("cls");
			cin >> value;
			s.push(value);
			break;
		case 3:
			system("cls");
			s.pop();
			break;
		case 4:
			system("cls");
			s.empty();
			break;
		case 5:
			system("cls");
			cout << s.count() << endl;
			break;
		case 6:
			system("cls");
			cout << "������� ����� ������: ";
			cin >> ind;
			link = s.getValue(ind);
			link->searchHeader();
			cout << value << endl;
			break;
		case 7:
			system("cls");
			cout << "������� ����� ������\n";
			cin >> ind;
			s.popInd(ind);
			break;
		case 8:
			cout << "������� ����� ���������� ������" << endl;
			cin >> ind;
			link = s.getValue(ind);
			link->preEditing();
			link->editing();
			break;
		case 9:
			file.writeFile(s);
			return;
		}
	}
}

template<class T>
void IStack<T>::menuType()
{
	int choice;
	while (true)
	{
		system("cls");
		cout << "���� ������ �����" << endl;
		cout << "1 - �������� ������������" << endl;
		cout << "2 - ��������" << endl;
		cout << "3 - ������ �������" << endl;
		cout << "4 - ����� ����" << endl;
		cout << "5 - ����� �� ���������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			system("cls");
			IStack <Mechanical_wristwatch>::menuFun(FILE_FOR_MECHANICAL_WRISTWATCH);
			break;
		}
		case 2: {
			system("cls");
			IStack <Hourglass>::menuFun(FILE_FOR_HOURGLASS);
			break;
		}
		case 3: {
			system("cls");
			IStack <Fitness_bracelet>::menuFun(FILE_FOR_FITNESS_BRACELET);
			break;
		}
		case 4: {
			system("cls");
			IStack <Smart_watch>::menuFun(FILE_FOR_SMART_WATCH);
			break;
		}
		case 5:
			return;
		}
	}
}
