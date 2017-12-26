#include "Queue.h"
#include <stdlib.h>
#include <iostream>

int main()
{
	Queue *a = new Queue;
	a->pop();
	a->push(0);
	a->push(4);
	a->push(2);
	a->push(-1);
	a->push(7);
	a->push(2);
	a->push(8);
	a->print();

//	a->sort();
//	a->bottle_sort();
//	a->insertion_sort();
//	a->merge_sort();
	a->quick_sort();

	a->find(3);
	a->find(4);
	std::cout << "Amount of elements in queue is " << a->amount() << "\n";
	a->pop();
	a->print();
	system("PAUSE");
}