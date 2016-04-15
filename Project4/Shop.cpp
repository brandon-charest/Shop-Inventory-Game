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
	list<item>::iterator lit;

	int i = 0;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		cout << i << ". "<< (*lit).getName() << " x " << (*lit).getCount() << endl;
		i++;
	}
}

bool Shop::purchaseItem(string name, item &newItem)
{
	list<item>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++) {
		if ((*lit).getName() == name) {
			newItem = (*lit);
			//once player has chosen an item return 1 of the requested item
			newItem.setCount(1);
			(*lit).removeOne();

			//if there are no more of a specific item remove it from list
			if ((*lit).getCount == 0) {
				_items.erase(lit);
			}
			//return true if item is found
			return true;
		}
	}

	//return false if item not found
	return false;
	
}

void Shop::addItem(item newItem)
{
	list<item>::iterator lit;
	//iterates through list of items
	for (lit = _items.begin(); lit != _items.end(); lit++) {
		//(*lit) takes presedence over the (.) operator
		//if new item is found add to list
		if ((*lit).getName() == newItem.getName()) {
			(*lit).addOne();
			return;
		}
	}

	_items.push_back(newItem);
}



