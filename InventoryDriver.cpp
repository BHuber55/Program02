#include "InventoryManager.h"
#include "Text.h"
using CSC2110::String;
#include "Keyboard.h"
using CSC2110::Keyboard;

#include <iostream>
#include <iomanip>
using namespace std;


//its printing out the user_input from the main menu after user clicks enter.. so I fixed it in the menu by taking out keyboard stuff...
//I think it looks better this way even if it's not using the way you wrote.
int inventoryChoice()
{
	//Keyboard* kb = Keyboard::getKeyboard();
	//int inv_choice = kb->getValidatedInt("Are you using (1) LIFO or (2) FIFO inventory management? ", 1, 2);
	int inv_choice;
	cout << "Are you using (1) LIFO or(2) FIFO inventory management ? ";
	cin >> inv_choice;
	cout << endl;
	return inv_choice;
}

//DO THIS
//buy Widgets (check invalid input and reprompt if necessary)
void buyWidgets(InventoryManager* im)
{
	//Keyboard* keyb = Keyboard::getKeyboard();
	int num_to_buy = 0;
	double cost = 0;

	while(num_to_buy == 0)
	{
		//num_to_buy = keyb->readInt("How many widgets would you like to buy? ");
		cout << "How many widgets would you like to buy? ";
		cin >> num_to_buy;
	}

	while(cost == 0)
	{
		//cost = keyb->readInt("What is the cost for each widget? ");
		cout << "What is the cost for each widget? ";
		cin >> cost;
		cout << endl;
	}

	im->buyWidgets(cost, num_to_buy);
}

//DO THIS
//sell Widgets and return the profit (check invalid input and reprompt if necessary)
double sellWidgets(InventoryManager* im)
{
	//Keyboard* keyb = Keyboard::getKeyboard();
	int num_to_sell = 0;
	double price = 0;

	while(num_to_sell == 0)
	{
		//num_to_sell = keyb->readInt("How many widgets would you like to sell? ");
		cout << "How many widgets would you like to sell? ";
		cin >> num_to_sell;
	}

	while(price == 0)
	{
		//price = keyb->readInt("What is the selling price for each widget? ");
		cout << "What is the selling price for each widget? ";
		cin >> price;
	}

	double profit = im->sellWidgets(price, num_to_sell);

	cout << "\nYour profit on this transaction is $" << profit << endl << endl;

	return profit;
}

bool mainMenu(InventoryManager* im)
{
	//sorry got rid of this because it was printing out users choice after user click enter.. Looks bad.
	//Keyboard* kb = Keyboard::getKeyboard();
	//int menu_choice = kb->getValidatedInt("1. Buy Widgets \r\n2. Sell Widgets\r\n3. Quit\r\nWhat would you like to do? ", 1, 3);

	int menu_choice;
	cout << "1. Buy Widgets \r\n2. Sell Widgets\r\n3. Quit\r\nWhat would you like to do? ";
	cin >> menu_choice;

	double profit = 0;

	if (menu_choice == 1)
	{
		buyWidgets(im);
		return 1;
	}
	else if (menu_choice == 2)
	{
		sellWidgets(im);
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	cout << setprecision(2) << fixed;

	int inv_choice = inventoryChoice();
	InventoryManager* im = new InventoryManager(inv_choice);

	bool ask = 1;
	while (ask)
	{
		ask = mainMenu(im);
	}

	double running_total = im->getTotalProfit();
	cout << "\nYour total profit for all transactions is $" << running_total << endl;

	delete im;
}