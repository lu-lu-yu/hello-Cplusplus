#include "stack_sequence.h"

SequenceStack::SequenceStack()
:m_top(0)
{

}

SequenceStack::~SequenceStack()
{

}

bool SequenceStack::push(Data& data)
{
	if (isFull())
		return false;

	m_datas[m_top++] = data;
	return true;
}

bool SequenceStack::pop(Data& data)
{
	if (isEmpty())
		return false;

	data = m_datas[--m_top];
	return true;
}

bool SequenceStack::head(Data& data)
{
	if (isEmpty())
		return false;

	data = m_datas[m_top - 1];
	return true;
}
//////////////////////////////////////////////////////////////////////////
void testSequenceStack()
{
	SequenceStack stack;
	stack.push(Data("1001", "zhangsan", 20));
	stack.push(Data("1002", "lisi", 20));
	stack.push(Data("1003", "wangwu", 20));

	Data headData;
	if (stack.pop(headData))
	{
		//headData.print(cout);
		cout << headData;
	}

	if (stack.pop(headData))
	{
		//headData.print(cout);
		cout << headData;
	}

	if (stack.isEmpty())
		cout << "stack is empty" << endl;
	else
		cout << "stack has elements" << endl;

	if (stack.pop(headData))
	{
		//headData.print(cout);
		cout << headData;
	}

	if (stack.isEmpty())
		cout << "stack is empty" << endl;
	if (!stack.pop(headData))
		cout << "pop error" << endl;
}
