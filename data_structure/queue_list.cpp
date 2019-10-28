#include "queue_list.h"

QueueList::QueueList()
:m_top(NULL), m_bottom(NULL), m_size(0)
{

}

QueueList::~QueueList()
{
	deleteAll();
}

bool QueueList::push(Data& data)
{
	ListNode* newNode = new ListNode;
	newNode->nodeData = data;
	newNode->nextNode = NULL;

	if (m_top)
		m_top->nextNode = newNode;
	else
		m_bottom = newNode;

	m_top = newNode;
	++m_size;
	return true;
}

bool QueueList::pop(Data& data)
{
	if (isEmpty())
		return false;

	data = m_bottom->nodeData;
	ListNode* curNode = m_bottom;
	m_bottom = m_bottom->nextNode;

	delete curNode;
	curNode = NULL;
	--m_size;
	return true;
}

bool QueueList::head(Data& data)
{
	if (isEmpty())
		return false;

	data = m_bottom->nodeData;
	return true;
}

bool QueueList::deleteAll()
{
	ListNode* curNode = m_bottom;
	ListNode* node = NULL;
	while (curNode)
	{
		node = curNode;
		curNode = curNode->nextNode;
		delete node;
		node = NULL;
	}

	m_top = NULL;
	m_bottom = NULL;
	m_size = 0;

	return true;
}

//////////////////////////////////////////////////////////////////////////
void testQueueList()
{
	QueueList queue;
	queue.push(Data("1001", "zhangsan", 20));
	queue.push(Data("1002", "lisi", 20));
	queue.push(Data("1003", "wangwu", 20));
	
	Data headData;
	if (queue.pop(headData))
	{
		//headData.print(cout);
		cout << headData;
	}
	
	if (queue.pop(headData))
	{
		//headData.print(cout);
		cout << headData;
	}
	
	if (queue.isEmpty())
	cout << "queue is empty" << endl;
	else
	cout << "queue has elements" << endl;
	
	if (queue.pop(headData))
	{
		//headData.print(cout);
		cout << headData;
	}
	
	if (queue.isEmpty())
	cout << "queue is empty" << endl;
	if (!queue.pop(headData))
	cout << "pop error" << endl;
}
