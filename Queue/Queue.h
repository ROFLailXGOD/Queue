#pragma once
#include "Node.h"

class Queue
{
private:
	QNode *head;
	QNode *tail;
public:
	Queue();
	Queue(const Queue&);
	~Queue();

	void push(int); // Добавление
	void pop(); // Удаление
	void find(int);
	int amount();
	void sort();
	void print();
};