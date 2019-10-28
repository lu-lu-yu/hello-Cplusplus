#ifndef _H_STACK_LIST_H_
#define _H_STACK_LIST_H_

#include "data.h"

// stack push和pop的那一端是head，最底下的元素指向NULL，按取数据的方向进行链表的链接
class StackList
{
public:
	StackList();
	~StackList();

	int		size()const { return m_size; }
	bool	isEmpty()const{ return 0 == m_size; }
//	bool	isFull()const{ return MAX_LENGTH == m_size; }
	bool	push(Data& data);
	bool	pop(Data& data);
	bool	head(Data& data);
	bool	deleteAll();

private:
	ListNode*	m_head;
	int			m_size;
};

void	testStackList();



#endif