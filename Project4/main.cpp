#include "main.h"
#include "item.h"
#include <list>
#include <iostream>
#include <string>
#include "Shop.h"
#include "Player.h"

using namespace std;


//Function prototypes (forward declaration)
void initShop(list<Shop> &shops);
void initPlayer(Player &player);
void enterShop(Player &player, Shop &shop);

int main() {

	//declare our variable
	list<Shop> shops;

	//iterator
	list<Shop>::iterator lit;
	Player player;
	string shopChoice;
	//initialize
	initPlayer(player);
	initShop(shops);
	

	//game loop
	bool isDone = false;
	while (isDone == false) {
		cout << "Shops:\n";
		int i = 1;
		for (lit = shops.begin(); lit != shops.end(); lit++) {
			cout << i << ". " << (*lit).getName() << endl;
			i++;
		}
		cout << "\nWhat shop would you like to enter? ";	
		getline(cin, shopChoice);
		cin.ignore(64, '\n');
		cin.clear();

		cout << "You inputted: " << shopChoice << endl;

		bool validShop = false;

		for (lit = shops.begin(); lit != shops.end(); lit++) {
			if ((*lit).getName() == shopChoice) {
				enterShop(player, (*lit));
				validShop = true;
			}			
		}

		if (validShop == false) {
			cout << "Invalid Shop!\n";
			system("PAUSE");
		
		}
	}	
	system("PAUSE");
	return 0;
}


void initShop(list<Shop> &shops) 
{
	shops.push_back(Shop("Moon Glade General Goods", 2000));
	shops.back().addItem(item("Health Potion", 15));
	shops.back().addItem(item("Mana Potion", 15));
	shops.back().addItem(item("Rugged Leather Chest", 100));
	shops.back().addItem(item("Rugged Leather Arms", 75));
	shops.back().addItem(item("Rugged Leather Legs", 75));
	shops.back().addItem(item("Rugged Leather Boots", 50));

	shops.push_back(Shop("Towns Blacksmith", 3600));
	shops.back().addItem(item("Iron Ingots", 50));
	shops.back().addItem(item("Silver Ore", 100));
	shops.back().addItem(item("Steel Sword", 600));
	shops.back().addItem(item("Iron Hammer", 300));
	shops.back().addItem(item("Iron Chest", 500));
	shops.back().addItem(item("Iron Arms", 275));
	shops.back().addItem(item("Iron Legs", 275));
	shops.back().addItem(item("Iron Boots", 250));

	shops.push_back(Shop("Murial's Magical Wears", 5200));
	shops.back().addItem(item("Witch's Staff", 500));
	shops.back().addItem(item("Mana Potion", 14));
	shops.back().addItem(item("Mage Robes", 300));
	shops.back().addItem(item("Wizard Hat", 100));
	shops.back().addItem(item("Pandora's Box", 199000));
	shops.back().addItem(item("Hag's Eye", 25));
	shops.back().addItem(item("Magic Amulet", 450));
	shops.back().addItem(item("Fire Stone", 200));


}
void initPlayer(Player &player)
{
	cout << "Enter thy name: ";
	string name;
	getline(cin, name);

	player.init(name, 100);
	player.addItem(item("Silver Sword", 25));
}

void enterShop(Player &player, Shop &shop)
{
	string itemName;
	item newItem("NOITEM", 0);
	char input;
	bool isDone = false;


	while (isDone == false) {
		shop.printShop();
		player.playerInventory();

		cout << "Would you like to Buy or Sell? Q to quit (B/S): ";
		cin >> input;


		if (input == 'Q' || input == 'q') {
			return;
		}
		if (input == 'B' || input =='b') {
			cout << "Enter the item you wish to buy: ";
			//clears input
			cin.ignore(64, '\n');
			cin.clear();
			getline(cin, itemName);

			if (shop.canAffordItem(itemName, player.getMoney())) {				
				
				if (shop.purchaseItem(itemName, newItem) == true) {
					//subtract money from player according to item value
					player.addMoney(-newItem.getValue());
					//add money to store
					shop.addMoney(newItem.getValue());
					player.addItem(newItem);
				} else {
					cout << "Invalid Choice!\n";
					system("PAUSE");
				}
			} else {
				cout << "You dont have enough money!\n";
				system("PAUSE");
			}
		} else { //sell
			cout << "Enter the item you wish to sell: ";

			//clears input
			cin.ignore(64, '\n');
			cin.clear();
			getline(cin, itemName);

			if (player.canAffordItem(itemName, shop.getMoney())) {

				if (player.removeItem(itemName, newItem) == true) {
					shop.addMoney(-newItem.getValue());
					shop.addItem(newItem);
					player.addMoney(newItem.getValue());
				} else {
					cout << "Invalid Choice! ";
					system("PAUSE");
				}
			} else {
				cout << "The shop dosent have enough money!\n";
				system("PAUSE");
			}
		}
	}
}


