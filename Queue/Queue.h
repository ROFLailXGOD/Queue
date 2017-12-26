#pragma once
#include "Node.h"

class Queue
{
private:
	QNode *head;
	QNode *tail;

	int* TurnIntoArr();
	void PutEmBack(int*, int);

	void quick_sortpr(int* arr, int left, int right);

	void merge(int*, int, int, int);
	void merge_sortpr(int*, int, int);
public:
	Queue();
	Queue(const Queue&);
	~Queue();

	void push(int); // Добавление
	void pop(); // Удаление
	void find(int);
	int amount();
	void sort();
	void bottle_sort(); // Ещё одна
	void quick_sort(); // И ещё
	void merge_sort(); // ДА ХВАТИТ УЖЕ, Я УСТАЛ!
	void insertion_sort(); // $$!0&!!!11
	void print();
};