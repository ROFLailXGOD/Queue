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
		head = new QNode();
		head->PutItem(a.head->GetItem());
		QNode *newPtr = head;
		for (QNode *prevPtr = a.head->GetNext(); prevPtr; prevPtr = prevPtr->GetNext())
		{
			newPtr->PutNext(new QNode());
			newPtr = newPtr->GetNext();
			newPtr->PutItem(prevPtr->GetItem());
		}
		newPtr->PutNext(NULL);
		tail = newPtr;
	}
}

Queue::~Queue()
{
	while (tail)
	{
		pop();
	}
}

void Queue::push(int item)
{
	QNode *newPtr = new QNode();
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
	if (!tail)
	{
		std::cout << "Queue is empty \n";
	}
	else
	{
		QNode *tmp = head;
		if (head == tail)
		{
			head = NULL;
			tail = NULL;
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

int* Queue::TurnIntoArr()
{
	int* arr = new int[this->amount()];
	int i = 0;
	for (QNode *ptr = head; ptr != NULL; ptr = ptr->GetNext())
	{
		arr[i] = ptr->GetItem();
		++i;
	}
	return arr;
}

void Queue::PutEmBack(int* arr, int size)
{
	while (tail)
	{
		pop();
	}
	for (int i = 0; i < size; ++i)
	{
		push(arr[i]);
	}
	delete[] arr;
}

void Queue::bottle_sort()
{
	int tmp = 0;
	int flag = 1;
	int count = 0;
	int* arr = TurnIntoArr();
	int size = amount();

	while (flag)
	{
		flag = 0;
		for (int i = 0; i < (size - 1); ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				++count;
				flag = 1;
			}
		}
	}
	PutEmBack(arr, size);
}

void Queue::quick_sortpr(int* arr, int left, int right)
{
	int l = left;
	int r = right;
	int op = arr[(l + r) / 2];
	int tmp = 0;
	while (l <= r)
	{
		while (arr[l] < op)
		{
			++l;
		}
		while (arr[r] > op)
		{
			--r;
		}
		if (l <= r)
		{
			tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
			++l;
			--r;
		}
	}

	if (left < r)
	{
		quick_sortpr(arr, left, r);
	}

	if (right > l)
	{
		quick_sortpr(arr, l, right);
	}
	return;
}

void Queue::quick_sort()
{
	int* arr = TurnIntoArr();
	int size = amount();
	quick_sortpr(arr, 0, size - 1);
	PutEmBack(arr, size);
}

void Queue::merge(int* arr, int first, int mid, int last)
{
	int* tempArr = new int[this->amount()];

	int firstl = first;
	int lastl = mid;
	int first2 = mid + 1;
	int last2 = last;
	int index = firstl;

	for (; (firstl <= lastl) && (first2 <= last2); ++index)
	{

		if (arr[firstl] < arr[first2])
		{
			tempArr[index] = arr[firstl];
			++firstl;
		}
		else
		{
			tempArr[index] = arr[first2];
			++first2;
		}
	}
	for (; firstl <= lastl; ++firstl, ++index)
	{
		tempArr[index] = arr[firstl];
	}

	for (; first2 <= last2; ++first2, ++index)
	{
		tempArr[index] = arr[first2];
	}
	for (index = first; index <= last; ++index)
	{
		arr[index] = tempArr[index];
	}
	delete[] tempArr;
}

void Queue::merge_sortpr(int* arr, int first, int last)

{
	if (first < last)
	{
		int mid = (first + last) / 2;

		merge_sortpr(arr, first, mid);
		merge_sortpr(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
}

void Queue::merge_sort()
{
	int* arr = TurnIntoArr();
	int size = amount();
	merge_sortpr(arr, 0, size - 1);
	PutEmBack(arr, size);
}

void Queue::insertion_sort()
{
	int* arr = TurnIntoArr();
	int size = amount();
	for (int unsorted = 1; unsorted < size; ++unsorted)
	{
		int nextltem = arr[unsorted];
		int sort = unsorted;
		for (; (sort > 0) && (arr[sort - 1] > nextltem); --sort)
		{
			arr[sort] = arr[sort - 1];
		}
		arr[sort] = nextltem;
	}
	PutEmBack(arr, size);
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
