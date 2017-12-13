#pragma once
class QNode
{
private:
	int item;
	QNode *next;
public:
	QNode();
	int GetItem();
	QNode* GetNext();
	void PutNext(QNode*);
	void PutItem(int);
};