#if !defined NULL
#define NULL 0
#endif

#include <iostream>

using namespace std;

template < class T >
class DequeDriver
{
	private:
		T** items;
		int back;
		int front;
		int max;
		int sz;

	public: 
		DequeArray();
		~DequeArray();

		bool isEmpty();
		int size();
		void resize();
		void dequeueAll();
		T* peek();
		void enqueue(T* item);
		T* dequeue();
		T* peekDeque();
		void enqueueDeque(T* item);
		T* dequeueDeque();
};

template < class T >
DequeDriver::DequeArray()
{
	max = 2;
	items = new T*[max];
	front = 0;
	back = max - 1;
	sz = 0;
}

template < class T >
DequeDriver::~DequeArray()
{
	delete[] items;
}

template < class T >
bool DequeDriver::isEmpty()
{
	return sz == 0;
}

template < class T >
int DequeDriver::size()
{
	return sz;
}

template < class T >
void DequeDriver::resize()
{
	T** temp = new T*[max * 2];
	int j = front;
	
	for (int i = 0; i < sz; i++)
	{
		temp[i] = items[j];
		j++;
		if (j == max)
		{
			j = 0;
		}
	}
}

template < class T >
void DequeDriver::dequeueAll()
{
	delete[] items;
	DequeArray();
}

template < class T >
T* DequeDriver::peek()
{
	T* item = NULL;

	if (!isEmpty())
	{
		item = items[front]
	}

	return item;
}

template < class T >
void DequeDriver::enqueue(T* item)
{
	if (sz == max)
	{
		resize();
	}

	//back = (back + 1) % max;
	back = back + 1;
	if (back == max)
	{
		back = 0;
	}
	items[back] = item;

	sz++;
}

template < class T >
T* DequeDriver::dequeue()
{
	T* item = NULL;

	if (!isEmpty())
	{
		item = items[front];
		items[front] = NULL;
		//front = (front + 1) % max;
		front = front + 1;
		
		if (front == max)
		{
			front = 0
		}

		sz++;
	}
	return item;
}

template < class T >
T* DequeDriver::peekDeque()
{

}

template < class T >
void DequeDriver::enqueueDeque(T* item)
{

}

template < class T >
T* DequeDriver::dequeueDeque()
{

}