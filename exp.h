#pragma once
#include <string>
#include <iostream>

using namespace std;

class exp {
protected:
	int code;
public:
	exp(int code) {
		this->code = code;
	}
	~exp() {};
};