#include "queue_sequence.h"

SequenceQueue::SequenceQueue()
:m_top(0), m_bottom(0)
{

}

SequenceQueue::~SequenceQueue()
{

}

bool SequenceQueue::push(Data& data)
{
	if (isFull())
		return false;

	m_data[m_top++] = data;
	return true;
}

bool SequenceQueue::pop(Data& data)
{
	if (isEmpty())
		return false;

	data = m_data[m_bottom++];
	return true;
}

bool SequenceQueue::head(Data& data)
{
	if (isEmpty())
		return false;

	data = m_data[m_bottom];
	return true;
}

//////////////////////////////////////////////////////////////////////////
void testSequenceQueue()
{
	SequenceQueue queue;
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
