#pragma once
#include <string>
#include <list>
#include "item.h"

using namespace std;
class Player
{
public:
	Player();

	void init(string name, int money);
	void playerInventory();
	bool canAffordItem(string name, int money);
	bool removeItem(string name, item &newItem);
	void addItem(item newItem);
	void addMoney(int money) { _money += money; }


	//getters
	int getMoney() { return _money; }
	void subtractMoney(int amount) { _money -= amount; }

private:
	string _name;
	int _money;
	list<item> _items;
};

