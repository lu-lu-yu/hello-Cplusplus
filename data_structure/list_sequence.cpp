#include "list_sequence.h"
#include <iostream>


SequenceList::SequenceList()
:m_listSize(0)
{

}

SequenceList::~SequenceList()
{

}

bool SequenceList::insert(Data& newData, int n)
{
	if (isFull())
		return false;
	int maxLen = m_listSize + 1;
	if (n < 1 || n > maxLen)
		return false;

	for (int i = maxLen; i > n - 1; --i)
	{
		m_datas[i] = m_datas[i - 1];
	}
	m_datas[n - 1] = newData;

	m_listSize++;
	return true;
}

bool SequenceList::append(Data& newData)
{
	if (isFull())
		return false;

	m_datas[m_listSize++] = newData;
	return true;
}

bool SequenceList::deleteOne(int n)
{
	if (isEmpty())
		return false;

	if (n < 1 || n > m_listSize)
		return false;

	for (int i = n - 1; i < m_listSize; ++i)
	{
		m_datas[i] = m_datas[i + 1];
	}
	m_listSize--;
	return true;
}

bool SequenceList::deleteAll()
{
	m_listSize = 0;
	return true;
}

bool SequenceList::getData(int n, Data& data) const
{
	if (n < 1 || n > m_listSize)
		return false;

	data = m_datas[n - 1];
	return true;
}

const Data& SequenceList::getData(int n) const
{
	if (n < 1 || n > m_listSize)
		return Data();

	return m_datas[n - 1];
}

bool SequenceList::isFull() const
{
	return MAX_LENGTH == m_listSize;
}

bool SequenceList::isEmpty() const
{
	return !m_listSize;
}

void SequenceList::printAll() const
{
	for (int i = 0; i < m_listSize; ++i)
	{
		Data curData = m_datas[i];
		cout << curData.m_key << " " << curData.m_name << " " << curData.m_age << endl;
	}
}
//////////////////////////////////////////////////////////////////////////
void testSequenceList()
{
	SequenceList seqList;
	Data newData("001", "zhangsan", 20);
	if (!seqList.append(newData))
	cout << "append data " << newData.m_key << " failed!" << endl;
	else
	cout << "append data " << newData.m_key << " success!" << endl;
	
	Data newData1("002", "lisi", 18);
	if (!seqList.insert(newData1, 3))
	cout << "insert data " << newData.m_key << " to 3 failed!" << endl;
	else
	cout << "insert data " << newData.m_key << " to 3 success!" << endl;
	if (!seqList.insert(newData1, 2))
	cout << "insert data " << newData.m_key << " to 2 failed!" << endl;
	else
	cout << "insert data " << newData.m_key << " to 2 success!" << endl;
	
	cout << "print all" << endl;
	seqList.printAll();
	
	if (seqList.deleteOne(3))
	cout << "delete data at 3 success!" << endl;
	else
	cout << "delete data at 3 failed!" << endl;
	
	if (seqList.deleteOne(0))
	cout << "delete data at 0 success!" << endl;
	else
	cout << "delete data at 0 failed!" << endl;
	
	if (seqList.deleteOne(1))
	cout << "delete data at 1 success!" << endl;
	else
	cout << "delete data at 1 failed!" << endl;
	
	cout << "print all" << endl;
	seqList.printAll();
}
