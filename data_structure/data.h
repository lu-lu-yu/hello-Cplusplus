#ifndef _H_DATA_H_
#define _H_DATA_H_

#include <iostream>
#include <string>
using namespace std;

#define MAX_LENGTH 100


//全局变量和函数声明要放在cpp中，在.h里的函数声明需在函数前加inline，
//当在.h中进行函数实现，且该文件被多个文件include时，vs编译会报错"fatal error LNK1169: 找到一个或多个多重定义的符号"

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

// 与 1 搭配的第一种可行方式
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


