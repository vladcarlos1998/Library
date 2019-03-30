#pragma once
#include <string>
#include "Carti.h"
#include <vector>

using namespace std;

class validator
{
public:
	validator(const vector<string>& errors) :mes{ errors } {}
	friend ostream& operator << (ostream& out, const validator& ex);
private:
	vector<string> mes;
};

ostream& operator << (ostream& out, const validator& ex);

class valid
{
public:
	void validare(const Carti& c);
};