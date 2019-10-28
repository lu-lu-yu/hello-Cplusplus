#ifndef _H_DATA_H_
#define _H_DATA_H_

#include <iostream>
#include <string>
using namespace std;

#define MAX_LENGTH 100


//ȫ�ֱ����ͺ�������Ҫ����cpp�У���.h��ĺ����������ں���ǰ��inline��
//����.h�н��к���ʵ�֣��Ҹ��ļ�������ļ�includeʱ��vs����ᱨ��"fatal error LNK1169: �ҵ�һ���������ض���ķ���"

class Data
{
	friend ostream& operator<< (ostream& os, const Data& data);// 1
public:
	Data();
	Data(string key, string name, int age);

	bool isValid() const { return m_age > -1; }
	void print(ostream& os) const;

	// 2
	/*friend ostream& operator<< (ostream& os, const Data& data)
	{
	os << data.m_key << " " << data.m_name << " " << data.m_age << endl;
	return os;
	}*/
	friend bool operator== (const Data& data1, const Data& data2)
	{
		if (data1.m_key != data2.m_key || data1.m_name != data2.m_name || data1.m_age != data2.m_age)
			return false;
		return true;
	}

public:
	string		m_key;
	string		m_name;
	int			m_age;
};

// �� 1 ����ĵ�һ�ֿ��з�ʽ
inline ostream& operator<< (ostream& os, const Data& data)
{
	os << data.m_key << " " << data.m_name << " " << data.m_age << endl;
	return os;
}


class ListNode
{
public:
	ListNode() :nextNode(NULL){}
	~ListNode() {nextNode = NULL; }
	Data		nodeData;
	ListNode*	nextNode;
};


class BinaryTreeNode
{
public:
	BinaryTreeNode() :leftSubNode(NULL), rightSubNode(NULL) {}
	~BinaryTreeNode() { leftSubNode = NULL; rightSubNode = NULL; }

	Data			nodeData;
	BinaryTreeNode*	leftSubNode;
	BinaryTreeNode*	rightSubNode;
};

#endif


