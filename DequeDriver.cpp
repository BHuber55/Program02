#if !defined NULL
#define NULL 0
#endif

#include "DequeArray.h"
#include <iostream>

using namespace std;

int main()
{
	//excuse the variable names.. Its late and I got bored. 
	//gonna make this really basic with lots of copy and pasting since thats all this really should take.

	DequeArray<int>* deque = new DequeArray<int>;

	int test1 = 1;
	int test2 = 2;
	int test3 = 3;
	int test4 = 4;
	int test5 = 5;
	int test6 = 6;
	int test7 = 7;
	int test8 = 8;
	int test9 = 9;
	int test10 = 10;

	deque->enqueue(&test1);
	deque->enqueue(&test2);
	deque->enqueue(&test3);
	deque->enqueue(&test4);					//this should now be 1 2 3 4

	int* random1 = deque->dequeueDeque(); 
	int* random2 = deque->dequeueDeque();	//since we dequeueDeque it should now be 1 2

	cout << *random1 << endl;				//should display 4
	cout << *random2 << endl;				//^^^ 3

	int* random3 = deque->peek();			//should show 2
	cout << *random3 << endl;

	deque->enqueue(&test5);				
	deque->enqueue(&test6);					//1 2 5 6

	deque->enqueueDeque(&test7);
	deque->enqueueDeque(&test8);
	deque->enqueueDeque(&test9);			//9 8 7 1 2 5 6

	int* random4 = deque->dequeue();
	int* random5 = deque->dequeue();		//7 1 2 5 6

	cout << *random4<< endl;				//should show 9
	cout << *random5 << endl;				//should show 8

	deque->enqueueDeque(&test10);			//10 7 1 2 5 6

	int sz = deque->size();

	for (int i = 0; i <= (sz/2); i++)
	{
		int* poppa = deque->dequeueDeque();
		if (poppa != NULL)
		{
			cout << "poppa: " << *poppa << endl;
		}
	}

	for(int i = 1; i <= sz; i++)
	{
		int* popper = deque->dequeue();
		if(popper != NULL)
		{
		cout << "popper: " << *popper << endl;
		}
	}
	return 0;
	//HOORAH!
}