#if !defined NULL
#define NULL 0
#endif

#if !defined (DEQUEARRAY_H)
#define DEQUEARRAY_H

#include <iostream>

using namespace std;

template < class T >
class DequeArray
{
	private:
		T** items;
		int back;
		int front;
		int max;
		int sz;

		void resize();

	public: 
		DequeArray();
		~DequeArray();

		bool isEmpty();
		int size();
		void dequeueAll();
		void push(T* item);
		T* peek();
		T* pop();
		void enqueue(T* item);
		T* dequeue();
		T* peekDeque();
		void enqueueDeque(T* item);
		T* dequeueDeque();
};

template < class T >
DequeArray<T>::DequeArray()
{
	max = 2;
	items = new T*[max];
	front = 0;
	back = max - 1;
	sz = 0;
}

template < class T >
DequeArray<T>::~DequeArray()
{
	delete[] items;
}

template < class T >
bool DequeArray<T>::isEmpty()
{
	return sz == 0;
}

template < class T >
int DequeArray<T>::size()
{
	return sz;
}

template < class T >
void DequeArray<T>::resize()
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

	front = 0;
	back = sz - 1;
	max = max*2;

	delete[] items;
	items = temp;
}

template < class T >
void DequeArray<T>::dequeueAll()
{
	delete[] items;
	DequeArray();
}

template < class T >
T* DequeArray<T>::peek()
{
	T* item = NULL;

	if (!isEmpty())
	{
		item = items[front];
	}

	return item;
}
 
template < class T >
void DequeArray<T>::enqueue(T* item)
{
	if (sz == max)
	{
		resize();
	}

	back = back + 1;
	if (back == max)
	{
		back = 0;
	}

	items[back] = item;
	sz++;
}

template < class T >
T* DequeArray<T>::dequeue()
{
	T* item = NULL;

	if (!isEmpty())
	{
		item = items[front];
		items[front] = NULL;
		front = front + 1;
		
		if (front == max)
		{
			front = 0;
		}

		sz--;
	}
	return item;
}

template < class T >
T* DequeArray<T>::peekDeque()
{
	//stil dont know. will come back and make sure this is right later.
	T* item = NULL;
	if (!isEmpty())
	{
		item = items[back];
	}
	return item;
}

template < class T >
void DequeArray<T>::enqueueDeque(T* item)
{
	if (sz == max)
	{
		resize();
	}

	front = front - 1;

	if (front < 0)
	{
		front = max - 1;
	}

	items[front] = item;


	sz++;
}

template < class T >
T* DequeArray<T>::dequeueDeque()
{
	T* item = NULL;

	if (!isEmpty())
	{

		item = items[back];
		items[back] = NULL;
		back = back - 1;
		if (back < 0)
		{
			back = max - 1;
		}
		sz--;
	}
	return item;
}

#endif