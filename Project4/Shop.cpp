#include "Shop.h"
#include <iostream>
using namespace std;

Shop::Shop(string name, int money)
{
	_name = name;
	_money = money;
}

void Shop::printShop()
{
	cout << "*** Welcome to " << _name << " ***\n";
	cout << "Money: " << _money << " GP\n\n";
	list<item>::iterator lit;

	int i = 0;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		cout << i << ". "<< (*lit).getName() << " x " << (*lit).getCount()<< "Price: "<<(*lit).getValue() << " GP" << endl;
		i++;
	}
	cout << endl;
}

bool Shop::canAffordItem(string name, int money)
{
	list<item>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getName() == name) {
			if ((*lit).getValue() <= money) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

bool Shop::purchaseItem(string name, item &newItem)
{
	list<item>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getName() == name) {
			newItem = (*lit);

			newItem.setCount(1);
			(*lit).removeOne();

			//if the item has a count of 0, remove it
			if ((*lit).getCount() == 0) {
				_items.erase(lit);
			}
			return true;
		}
	}
	return false;
	
}

void Shop::addItem(item newItem)
{

	//iterates through list of items
	list<item>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		//if the item is already in the shop, just increase count and return
		if ((*lit).getName() == newItem.getName()) {
			(*lit).addOne();
			return;
		}
	}

	_items.push_back(newItem);
}



