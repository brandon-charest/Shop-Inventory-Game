#include "item.h"



item::item(string name, int value)
{
	_name = name;
	_value = value;
	_count = 1;

}

void item::addOne()
{
	_count++;
}

void item::removeOne()
{
	if (_count > 0) {
		_count--;
	}
}