#include "stack_list.h"

StackList::StackList()
:m_head(NULL), m_size(0)
{

}

StackList::~StackList()
{
	deleteAll();
}

bool StackList::push(Data& data)
{
	ListNode* newNode = new ListNode;
	newNode->nodeData = data;

	newNode->nextNode = m_head;

	m_head = newNode;
	++m_size;

	return true;
}

bool StackList::pop(Data& data)
{
	if (isEmpty())
		return false;

	ListNode* topNode = m_head;
	data = topNode->nodeData;
	m_head = m_head->nextNode;
	delete topNode;
	topNode = NULL;
	--m_size;

	return true;
}

bool StackList::head(Data& data)
{
	if (isEmpty())
		return false;

	data = m_head->nodeData;

	return true;
}

bool StackList::deleteAll()
{
	ListNode* curNode = NULL;
	ListNode* node = m_head;
	while (node)
	{
		curNode = node;
		node = node->nextNode;
		delete curNode;
		curNode = NULL;
	}
	m_head = NULL;
	m_size = 0;

	return true;
}
//////////////////////////////////////////////////////////////////////////
void testStackList()
{
	StackList stack;
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
