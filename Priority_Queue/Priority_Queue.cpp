#include "Priority_Queue.h"

Priority::Priority(int size)
	: m_countdata(NULL)
{
	m_data = new string[size+1];
	m_length = new int[size+1];
}

Priority::~Priority()
{
	delete[] m_data;
}

int Priority::getHiChildIndex(int index)
{
	if (getleftindex(index) > m_countdata)
	{
		return 0;
	}
	else if (getleftindex(index) == m_countdata)
	{
		return getleftindex(index);
	}
	else
	{
		if (PriorityComp(getlength(getleftindex(index)), getlength(getrightindex(index))) > 0)
		{
			return getleftindex(index);
		}
		else
		{
			return getrightindex(index);
		}
	}
}

void Priority::Insert(string data)
{
	int index = m_countdata+1;

	while (index != 1)
	{
		if (PriorityComp(data.size(), m_length[getparentIndex(index)]) > 0)
		{
			m_data[index] = m_data[getparentIndex(index)];
			m_length[index] = m_length[getparentIndex(index)];
			index = getparentIndex(index);
		}
		else
		{
			break;
		}
	}

	m_data[index] = data;
	m_length[index] = data.size();
	++m_countdata;
}

string Priority::Delete()
{
	if (empty())
	{
		return "FAILD : IT'S EMPTY";
	}
	else
	{
		string headdata = m_data[1];
		string lastdata = m_data[m_countdata];

		int parentindex = 1;
		int childindex;
		while (childindex = getHiChildIndex(parentindex))
		{
			if (PriorityComp(lastdata.size(), m_length[childindex]) >= 0)
			{
				break;
			}
			else
			{
				m_data[parentindex] = m_data[childindex];
				m_length[parentindex] = m_length[childindex];
				parentindex = childindex;
			}
		}
		m_data[parentindex] = lastdata;
		m_length[parentindex] = lastdata.size();
		--m_countdata;

		return headdata;
	}
}

string Priority::getData(int index)
{
	return m_data[index];
}

void Priority::setData(int index, string data)
{
	m_data[index] = data;
	m_length[index] = data.size();
}

int Priority::getlength(int index)
{
	return m_length[index];
}

int Priority::getparentIndex(int index)
{
	return index/2;
}

int Priority::getleftindex(int index)
{
	return index*2;
}

int Priority::getrightindex(int index)
{
	return (index*2+1);
}

bool Priority::empty()
{
	if (m_countdata == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Priority::PriorityComp(int length1, int length2)
{
	return length2-length1;
}

