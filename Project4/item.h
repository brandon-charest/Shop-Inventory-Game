#pragma once
#include <string>

using namespace std;
class item
{
public:
	item(string name, int value);

	void addOne();
	void removeOne();

	//getters
	string getName() { return _name; }
	int getValue() { return _value; }
	int getCount() { return _count; }

	//setters
	void setCount(int count) { _count = count; }

private:
	string _name;
	int _value;
	int _count;
};

