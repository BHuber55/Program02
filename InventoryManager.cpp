#include "InventoryManager.h"

#include <iostream>
using namespace std;

InventoryManager::InventoryManager(int inventory_choice) //LIFO or FIFO
{
	if (inventory_choice == 1)	//this is LIFO, use a stack
	{
		use_LIFO = true;
		stack = new Stack<Widget>;
		total_profit = 0;
		queue = NULL;
	}

	else			//FIFO, so use a queue
	{
		use_LIFO = false;
		queue = new Queue <Widget>;
		total_profit = 0;
		stack = NULL;
	}
}

InventoryManager::~InventoryManager()
{
	if (use_LIFO)
	{
		delete stack;
	}
	else
	{
		delete queue;
	}
}

void InventoryManager::buyWidgets(double cost, int num_to_buy)
{
	Widget* widget;

	for (int i = 0; i < num_to_buy; i++)
	{
		
		widget = new Widget(cost);

		if (use_LIFO)
		{
			stack->push(widget);
		}

		else
		{
			queue->enqueue(widget);
		}
	}
}

double InventoryManager::getTotalProfit()
{
	return total_profit;
}

double InventoryManager::sellWidgets(double price, int num_to_sell)
{
	Widget* widget;

	double profit = 0;
	double cost = 0;

	//issue is here with this loop.. itll sell 1 item, but wont sell any more than that. doesnt like going from 2 to 3 in my cout statements.
	for (int i = 0; i < num_to_sell; i++)
	{
		if (use_LIFO)
		{
			if (!(stack->isEmpty()) )
			{
				widget = stack->pop();
				cost = widget->getCost();

				profit = profit + (price - cost);
			}
		}

		else
		{
			if (!queue->isEmpty())
			{
				widget = queue->dequeue();
				cost = widget->getCost();

				profit = profit + (price - cost);
			}
		}
	}

	total_profit = total_profit + profit;

	return profit;
}