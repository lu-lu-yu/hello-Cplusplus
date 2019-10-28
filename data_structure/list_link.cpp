#include "list_link.h"
#include <iostream>

LinkList::LinkList()
	:m_head(NULL), m_listSize(0)
{
}

LinkList::~LinkList()
{
	deleteAll();
	m_head = NULL;
}

bool LinkList::append(ListNode* newNode)
{
	if (0 == m_listSize)//Ê×ÔªËØ
		m_head = newNode;
	else
	{
		ListNode* temp = m_head;
		while (temp->nextNode)
			temp = temp->nextNode;
		
		temp->nextNode = newNode;
		newNode->nextNode = NULL;
	}

	++m_listSize;

	return true;
}

bool LinkList::insert(ListNode* newNode, int n)
{
	if (n < 0 || n > m_listSize)
		return false;

	if (0 == n)
	{
		newNode->nextNode = m_head;
		m_head = newNode;
	}
	else
	{
		ListNode* preNode = NULL;
		ListNode* tempNode = m_head;
		for (int i = 0; i < n; ++i)
		{
			preNode = tempNode;
			tempNode = tempNode->nextNode;
		}
	
		newNode->nextNode = tempNode;
		preNode->nextNode = newNode;
	}
	

	++m_listSize;

	return true;
}

bool LinkList::deleteOne(int n)
{
	if (n < 0 || n > m_listSize - 1)
		return false;

	ListNode* node = NULL;
	if (!find(n, node))
		return false;

	delete node;
	node = NULL;

	--m_listSize;
	return true;
}

bool LinkList::deleteAll()
{
	ListNode* temp = m_head; 
	ListNode* curNode = NULL;
	while (!temp)
	{
		curNode = temp;
		temp = temp->nextNode;
		delete curNode;
		curNode = NULL;
	}

	m_listSize = 0;
	m_head = NULL;
	return true;
}

bool LinkList::find(int n, ListNode*& node)
{
	if (n < 0 || n > m_listSize - 1)
		return false;

	node = NULL;

	ListNode* tempNode = m_head;
	for (int i = 0; i < n; ++i)
		tempNode = tempNode->nextNode;
	
	node = tempNode;

	return true;
}

void LinkList::printAll() const
{
	ListNode* temp = m_head;
	while (temp)
	{
		Data curData = temp->nodeData;
		cout << curData.m_key << " " << curData.m_name << " " << curData.m_age << endl;

		temp = temp->nextNode;
	}
}
//////////////////////////////////////////////////////////////////////////
void testLinkList()
{
	LinkList testList;
	ListNode* newNode = new ListNode;
	newNode->nodeData = Data("1001", "zhangsan", 20);
	if (testList.insert(newNode, 0))
	cout << "Insert data success, newNode = 1001" << endl;
	else
	cout << "Insert data failed, newNode = 1001" << endl;
	
	ListNode* newNode1 = new ListNode;
	newNode1->nodeData = Data("1002", "lisi", 20);
	if (testList.append(newNode1))
	cout << "Append data success, newNode = 1002" << endl;
	else
	cout << "Append data failed, newNode = 1002" << endl;
	
	ListNode* newNode2 = new ListNode;
	newNode2->nodeData = Data("1003", "zhaowu", 20);
	if (testList.insert(newNode2, 0))
	cout << "Insert data success, newNode = 1003" << endl;
	else
	cout << "Insert data failed, newNode = 1003" << endl;
	
	ListNode* newNode3 = new ListNode;
	newNode3->nodeData = Data("1004", "wangliu", 20);
	if (testList.insert(newNode3, 3))
	cout << "Insert data success, newNode = 1004" << endl;
	else
	cout << "Insert data failed, newNode = 1004" << endl;
	
	testList.printAll();
	
	ListNode* testNode = NULL;
	if (testList.find(2, testNode) && testNode)
	cout << "find index==2 node, node= " << testNode->nodeData.m_key << " " << testNode->nodeData.m_name << endl;
	else
	cout << "find nothing" << endl;
	
	ListNode* newNode4 = new ListNode;
	newNode4->nodeData = Data("1005", "dongqi", 20);
	if (testList.insert(newNode4, 3))
	cout << "Insert data success, newNode = 1005" << endl;
	else
	cout << "Insert data failed, newNode = 1005" << endl;
	
	testList.printAll();
}
