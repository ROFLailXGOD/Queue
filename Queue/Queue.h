#pragma once

class Queue
{
private:
	struct QNode
	{
		int item;
		QNode *next;
	};
	QNode *head;
	QNode *tail;
public:
	Queue();
	Queue(const Queue&);
	~Queue();

	void push(int); // ����������
	void pop(); // ��������
	void find(int);
	int amount();
	void sort();
	void print();
};