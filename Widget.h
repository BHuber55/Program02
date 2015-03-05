#if !defined NULL
#define NULL 0
#endif

#include "DequeArray.h"

//no reason to make it templated.
class Widget
{
	private:
		double cost;		//cost of ea widget.

	public:
		Widget(double price);
		~Widget();

		double getCost();
};
