#include "Node.h"
#include <stdlib.h>

QNode::QNode()
{
	next = NULL;
}

int QNode::GetItem()
{
	return item;
}

QNode* QNode::GetNext()
{
	return next;
}

void QNode::PutNext(QNode* n)
{
	next = n;
}

void QNode::PutItem(int value)
{
	item = value;
}