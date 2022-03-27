#pragma once
#include "Stack.h"
#include <iomanip>
#include <iostream>
#include "Watch.h"
#include "checkup.h"

template<class T>
class txtFile
{
	string fileName;
	ifstream fin;
	ofstream fout;
public:
	txtFile(string fileName);
	~txtFile();

	void readFile(Stack<T>&);
	void writeFile(Stack<T>&);
};


//
//
template <class T>
txtFile<T>::txtFile(string fileName)
{
	this->fileName = fileName;
};
template <class T>
txtFile<T>::~txtFile() {
	this->fin.close();
	this->fout.close();
}

template <class T>
void txtFile<T>::readFile(Stack<T>& s) {
	fin.open(fileName);
	
	if (fileOpening(fin)) {
		fin.seekg(0, std::ios_base::beg);
		T value;
		while (!fin.eof()) {
			fin >> value;
			s.push(value);
		}
	}
}

template <class T>
void txtFile<T>::writeFile(Stack<T>& s) {
	fout.open(fileName);

	for (int i = 1; i < s.count(); i++) {
		fout << *s.getValue(i) <<endl;
	}
	fout << *s.getValue(s.head->ind);
}