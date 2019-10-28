#ifndef _H_QUEUE_LIST_H_
#define _H_QUEUE_LIST_H_

#include "data.h"
// queue push����һ��ָ��NULL��pop����һ����head����ȡ���ݵķ���������������
class QueueList
{
public:
	QueueList();
	~QueueList();

	int		size()const { return m_size; }
	bool	isEmpty()const { return 0 == m_size; }
//	bool	isFull()const { return MAX_LENGTH == m_top; }
	bool	push(Data& data);
	bool	pop(Data& data);
	bool	head(Data& data);
	bool	deleteAll();

private:
	ListNode*	m_top;
	ListNode*	m_bottom;
	int			m_size;
};

void	testQueueList();


#endif