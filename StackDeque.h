#if !defined NULL
#define NULL 0
#endif

#if !defined (STACKDEQUE_H)
#define STACKDEQUE_H

//this is for a lifo style
#include "DequeArray.h"

template < class T >
class Stack
{
	private:
		DequeArray<T>* deque;

	public:
		Stack();
		~Stack();

		bool isEmpty();
		int size();
		void popAll();

		T* peek();
		void push(T* item);
		T* pop();
};

template < class T >
Stack<T>::Stack()
{
	deque = new DequeArray<T>();
}

template < class T >
Stack<T>::~Stack()
{
	deque->~DequeArray();
}

template < class T >
bool Stack<T>::isEmpty()
{
	return deque->isEmpty();
}

template < class T >
int Stack<T>::size()
{
	return deque->size();
}

template < class T >
void Stack<T>::popAll()
{
	deque->dequeueAll();
}

template < class T >
T* Stack<T>::peek()
{
	return deque->peekDeque();
}

template < class T >
void Stack<T>::push(T* item)
{
	deque->enqueue(item);
}

template < class T >
T* Stack<T>::pop()
{
	return deque->dequeueDeque();
}

#endif