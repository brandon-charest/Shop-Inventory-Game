#pragma once
#include <string>
#include <list>
#include "item.h"

class Shop
{
public:
	Shop(string name, int money);

	void printShop();
	bool canAffordItem(string name, int money);
	bool purchaseItem(string name, item &newItem);
	void addItem(item newItem);
	void addMoney(int money) { _money += money; }

	//getters
	int getMoney() { return _money; }
	string getName() { return _name; }

private:
	string _name;
	list<item> _items;
	int _money;
};

