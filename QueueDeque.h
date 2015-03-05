#if !defined NULL
#define NULL 0
#endif

#if !defined (QUEUEDEQUE_H)
#define QUEUEDEQUE_H

//this is for fifo style?
#include "DequeArray.h"
template < class T >
class Queue
{
	private:
		DequeArray<T>* deque;

	public:
		Queue();
		~Queue();

		bool isEmpty();
		int size();
		T* peek();

		void dequeueAll();
		void enqueue(T* item);
		T* dequeue();
};

template < class T >
Queue<T>::Queue()
{
	deque = new DequeArray<T>();
}

template < class T >
Queue<T>::~Queue()
{
	deque->~DequeArray(); 
}

template < class T >
bool Queue<T>::isEmpty()
{
	return deque->isEmpty();
}

template < class T >
int Queue<T>::size()
{
	return deque->size();
}

template < class T >
T* Queue<T>::peek()
{
	return deque->peek();
}

template < class T >
void Queue<T>::dequeueAll()
{
	deque->dequeueAll();
}

template < class T >
void Queue<T>::enqueue(T* item)
{
	deque->enqueue(item);
}

template < class T >
T* Queue<T>::dequeue()
{
	return deque->dequeue();
}

#endif

