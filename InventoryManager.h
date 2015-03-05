#if !defined NULL
#define NULL 0
#endif

#if !defined (INVENTORYMANAGER_H)
#define INVENTORYMANAGER_H

#include "StackDeque.h"
#include "QueueDeque.h"
#include "Widget.h"

/*
	About:
	This class is used with the widget class.
	It is an inventory manager that asks whether or not you would like to use LIFO (last in first out)
		or FIFO (first in first out) in order to manage your inventory.
	This will calculate your total profit between you buying and selling your 'widgets'.
*/

class InventoryManager
{
	private:
		bool use_LIFO;
		Stack<Widget>* stack;
		Queue<Widget>* queue;
		double total_profit;

	public:
		/*
		Pre:	if inventory_choice == 1 then user wants LIFO,
				if inventory_choice == 2 then user wants FIFO.
		Post:	creates a method for storing widgets depending users inventory_choice.
		*/
		InventoryManager(int inventory_choice);
		/*
		Pre:	NONE
		Post:	Deletes the method that was created in the InventoryManager()
		*/
		~InventoryManager();
		/*
		Pre:	cost == what the widgets cost the user.
				num_to_buy == how many widgets the users would like to purchase.
		Post:	Adds the widgets to the method being used.
		*/
		void buyWidgets(double cost, int num_to_buy);
		/*
		Pre:	requires InvntoryManager to have already been constructed.
		Post:	returns total profit from the buying and selling at that moment.
		*/
		double getTotalProfit();
		/*
		Pre:	price == the price that the user is selling the widgets for.
				num_to_sell == how many widgets the users intends to sell.
		Post:	Removes num_to_sell items
				Calculates profit made from buying and selling each individual widget, adds this profit to total profit.
				Returns profit for that transaction.
		*/
		double sellWidgets(double price, int num_to_sell);
};

#endif