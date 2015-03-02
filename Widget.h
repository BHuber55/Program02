#include <iostream>

using namespace std;

//no need to template this.. no reason to make it templated.
class Widget
{
	private:
		double cost;
		double revenue; //?

	public:
		Widget();
		~Widget();
		double getCost();

};

Widget::Widget()
{

}

Widget::~Widget
{

}

double Widget::getCost()
{
	return cost;
}