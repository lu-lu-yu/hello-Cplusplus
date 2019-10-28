#ifndef _H_QUEUE_SEQUENCE_H_
#define _H_QUEUE_SEQUENCE_H_

#include "data.h"

class SequenceQueue
{
public:
	SequenceQueue();
	~SequenceQueue();

	int		size()const { return m_top - m_bottom; }
	bool	isEmpty()const { return 0 == size(); }
	bool	isFull()const { return MAX_LENGTH == m_top; }
	bool	push(Data& data);
	bool	pop(Data& data);
	bool	head(Data& data);

private:
	Data	m_data[MAX_LENGTH];
	int		m_top;
	int		m_bottom;
};

void	testSequenceQueue();


#endif