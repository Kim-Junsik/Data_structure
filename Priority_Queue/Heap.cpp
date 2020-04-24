#include "Heap.h"

int Heap::PriorityComp(Hdata d1, Hdata d2)
{
	return d2 - d1;
}


int getparentindex(int index)
{
	return index / 2;
}

int getchildleftindex(int index)
{
	return index * 2;
}

int getchildrightindex(int index)
{
	return index * 2 + 1;
}

void Heap::Hinit(Heap * hp)
{
	countdata = NULL;
}

bool Heap::Hempty(Heap * hp)
{
	if (countdata == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int gethichildindex(Heap *hp, int index)
{
	if (getchildleftindex(index) > hp->getcountdata())
		return 0;
	else if (getchildleftindex(index) == hp->getcountdata())
	{
		return getchildleftindex(index);
	}
	else
	{
		if (hp->PriorityComp(hp->getdata(getchildleftindex(index)),hp->getdata(getchildrightindex(index))) < 0)
		{
			return getchildrightindex(index);
		}
		else
		{
			return getchildleftindex(index);
		}

	}
}

void Heap::Hinsert(Heap * hp, Hdata data)
{
	int index = hp->countdata + 1;

	while (index != 1)
	{
		if (PriorityComp(data, hp->getdata(getparentindex(index))) > 0)
		{
			this->data[index] = this->data[getparentindex(index)];
			index = getparentindex(index);
		}
		else
		{
			break;
		}
	}

	this->setdata(index, data);
	hp->countdata += 1;
}

Hdata Heap::Hdelete(Heap * hp)
{
	Hdata headData = hp->getdata(1);
	Hdata lastData = hp->getdata(hp->getcountdata());

	int parentindex = 1;
	int childindex = 0;

	while (childindex = gethichildindex(hp, parentindex))
	{
		if (hp->PriorityComp(lastData, hp->getdata(childindex)) >= 0)
			break;

		hp->setdata(parentindex, hp->getdata(childindex));
		parentindex = childindex;
	}

	hp->setdata(parentindex, lastData);
	hp->setcountdata(1);
	return headData;
}
