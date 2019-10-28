#ifndef _H_STACK_SEQUENCE_H_
#define _H_STACK_SEQUENCE_H_

#include "data.h"

class SequenceStack
{
public:
	SequenceStack();
	~SequenceStack();

public:
	int		size()const { return m_top; }
	bool	isEmpty()const{ return 0 == m_top; }
	bool	isFull()const{ return MAX_LENGTH == m_top; }
	bool	push(Data& data);
	bool	pop(Data& data);
	bool	head(Data& data);

private:
	Data	m_datas[MAX_LENGTH];
	int		m_top;
};

void	testSequenceStack();


#endif