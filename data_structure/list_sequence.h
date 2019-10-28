#ifndef _H_LIST_SEQUENCE_H_
#define _H_LIST_SEQUENCE_H_

#include "data.h"

class SequenceList
{
public:
	SequenceList();
	~SequenceList();

public:
	int			size() const{ return m_listSize; }
	bool		insert(Data& newData, int n);//n: the array index + 1
	bool		append(Data& newData);
	bool		deleteOne(int n);
	bool		deleteAll();
	bool		getData(int n, Data& data) const;
	const Data&	getData(int n) const;
	void		printAll() const;
	bool		isFull() const;
	bool		isEmpty() const;

private:
	Data	m_datas[MAX_LENGTH];
	int		m_listSize;
};

void	testSequenceList();


#endif