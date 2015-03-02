#include <iostream>

using namespace std;

//no need for templates since its 
class InventoryManager
{
	private:
		//if request lifo use stackdeque
		//if fifo use quedeque
		stackDeque<Widget>*;
		queDeque<Widget>*;

	public:
		InventoryManager(int inventory_choice); //LIFO or FIFO
		~InventoryManager();
		void buyWidgets(double cost, int num_to_buy);
		double getTotalProfit();
		double sellWidgets(double price, int num_to_sell);
};

InventoryManager(int inventory_choice) //LIFO or FIFO
{
	/*if(LIFO)
	push onto stack
	*/

	/*if(FIFO)
	enque onto fifo
	*/
}

~InventoryManager()
{

}
void buyWidgets(double cost, int num_to_buy);
{

}

double getTotalProfit();
{
	double profit;
}

double sellWidgets(double price, int num_to_sell)
{

}