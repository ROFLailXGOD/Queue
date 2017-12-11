#include "Queue.h"
#include <stdlib.h>
#include <iostream>

Queue::Queue()
{
	head = NULL;
	tail = NULL;
}

Queue::Queue(const Queue& a)
{
	if (!a.head)
	{
		head == NULL;
		tail == NULL;
	}
	else
	{
		head = new QNode;
		head->item = a.head->item;
		QNode *newPtr = head;
		for (QNode *prevPtr = a.head->next; prevPtr; prevPtr = prevPtr->next)
		{
			newPtr->next = new QNode;
			newPtr = newPtr->next;
			newPtr->item = prevPtr->item;
		}
		newPtr->next = NULL;
		tail = newPtr;
	}
}

Queue::~Queue()
{
	while (head)
	{
		pop();
	}
}

void Queue::push(int item)
{
	QNode *newPtr = new QNode;
	if (!newPtr)
	{
		std::cout << "Memory allocation is impossible" << "\n";
	}
	else
	{
		newPtr->item = item;
		if (!head)
		{
			head = newPtr;
		}
		else
		{
			newPtr->next = NULL;
			tail->next = newPtr;
		}
		tail = newPtr;
	}
}

void Queue::pop()
{
	if (!head)
	{
		std::cout << "Queue is empty \n";
	}
	else
	{
		QNode *tmp = head;
		if (head == tail)
		{
			head == NULL;
			tail == NULL;
		}
		else
		{
			head = head->next;
		}
		tmp->next = NULL;
		delete tmp;
	}
}

void Queue::find(int item)
{
	QNode *ptr = head;
	while (ptr)
	{
		if (ptr->item == item)
		{
			std::cout << "Item " << item << " is found \n";
			break;
		}
		ptr = ptr->next;
	}
	if (!ptr)
	{
		std::cout << "Item " << item << " isn't found \n";
	}
}

int Queue::amount()
{
	int count = 0;
	QNode *ptr = head;
	while (ptr)
	{
		++count;
		ptr = ptr->next;
	}
	return count;
}

void Queue::sort()
{
	if (head)
	{
		for (int i = 0; i < amount() - 1; ++i)
		{
			int tmp = head->item;
			pop();
			int steps = 0;
			while (steps < amount())
			{
//				print();
				if (tmp < head->item)
				{
					push(tmp);
					tmp = head->item;
					pop();
					steps = 0;
				}
				else
				{
					push(head->item);
					pop();
					++steps;
				}
			}
			push(tmp);
//			std::cout << "\n";
		}
	}
}

void Queue::print()
{
	QNode *ptr = head;
	std::cout << "Queue: ";
	while (ptr)
	{
		std::cout << ptr->item << " ";
		ptr = ptr->next;
	}
	std::cout << "\n";
}
