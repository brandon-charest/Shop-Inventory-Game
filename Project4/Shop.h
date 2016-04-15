#pragma once
#include <string>
#include <list>
#include "item.h"

class Shop
{
public:
	Shop(string name, int money);

	void printShop();
	bool purchaseItem(string name, item &newItem);
	void addItem(item newItem);

	//getters
	string getName() { return _name; }

private:
	string _name;
	list<item> _items;
	int _money;
};

