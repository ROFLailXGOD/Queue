#include "Queue.h"
#include "Node.h"
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
		head->PutItem(a.head->GetItem());
		QNode *newPtr = head;
		for (QNode *prevPtr = a.head->GetNext(); prevPtr; prevPtr = prevPtr->GetNext())
		{
			newPtr->PutNext(new QNode);
			newPtr = newPtr->GetNext();
			newPtr->PutItem(prevPtr->GetItem());
		}
		newPtr->PutNext(NULL);
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
		newPtr->PutItem(item);
		if (!head)
		{
			head = newPtr;
		}
		else
		{
			newPtr->PutNext(NULL);
			tail->PutNext(newPtr);
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
			head = head->GetNext();
		}
		tmp->PutNext(NULL);
		delete tmp;
	}
}

void Queue::find(int item)
{
	QNode *ptr = head;
	while (ptr)
	{
		if (ptr->GetItem() == item)
		{
			std::cout << "Item " << item << " is found \n";
			break;
		}
		ptr = ptr->GetNext();
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
		ptr = ptr->GetNext();
	}
	return count;
}

void Queue::sort()
{
	if (head)
	{
		for (int i = 0; i < amount() - 1; ++i)
		{
			int tmp = head->GetItem();
			pop();
			int steps = 0;
			while (steps < amount())
			{
//				print();
				if (tmp < head->GetItem())
				{
					push(tmp);
					tmp = head->GetItem();
					pop();
					steps = 0;
				}
				else
				{
					push(head->GetItem());
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
		std::cout << ptr->GetItem() << " ";
		ptr = ptr->GetNext();
	}
	std::cout << "\n";
}
