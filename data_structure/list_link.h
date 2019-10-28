#ifndef _H_LIST_LINK_H_
#define _H_LIST_LINK_H_

#include "data.h"

class LinkList
{
public:
	LinkList();
	~LinkList();

public:
	int		size()const {return m_listSize;}
	bool	append(ListNode* newNode);
	bool	insert(ListNode* newNode, int n);//��λ��n����ýڵ㣬n��ѭ��0��ʼ
	bool	deleteOne(int n);
	bool	deleteAll();
	bool	find(int n, ListNode*& node);
	bool	isEmpty()const {return 0 == m_listSize;}
	void	printAll()const;

private:
	ListNode*	m_head;
	int			m_listSize;
};

void	testLinkList();


#endif