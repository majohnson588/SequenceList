#include "Seqlist.h"

void SLInit(SL* ps)
{
	assert(ps != NULL);

	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps != NULL);

	SLCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}

void SLPrint(SL* ps)
{
	assert(ps != NULL);

	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps != NULL);

	SLCheckCapacity(ps);

	//挪动数据
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}

	ps->a[0] = x;
	ps->size++;
} 

void SLCheckCapacity(SL* ps)
{
	assert(ps != NULL);

	//检查容量空间，满了扩容
	if (ps->size == ps->capacity)
	{
		int NewCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = realloc(ps->a, sizeof(SLDataType) * NewCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			//exit(-1);
			return;
		}
		ps->a = tmp;
		ps->capacity = NewCapacity;
	}
}

void SLPopBack(SL* ps)
{
	//ps->a[ps->size - 1] = 0;
	//温柔检查
	//if (ps->size == 0)
	//{
	//	printf("SeqList is empty\n");
	//	return;
	//}

	//暴力检查
	assert(ps != NULL);

	assert(ps->size > 0);

	ps->size--;
}

void SLDestory(SL* ps)
{
	assert(ps != NULL);

	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->capacity = ps->size = 0;
	}
}

void SLPopFront(SL* ps)
{
	assert(ps != NULL);

	assert(ps->size > 0);

	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}

	ps->size--;
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(ps >= 0 && pos <= ps->size);

	SLCheckCapacity(ps);

	//挪用数据
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	int begin = pos;
	while (begin < ps->size - 1)
	{
		ps->a[begin] = ps->a[begin + 1];
		++begin;
	}

	ps->size--;
}

int SLFind(SL* ps, SLDataType x)
{
	int pos = 0;
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			pos = i;
			return pos;
		}
		else
			return -1;
	}
}

int Modify(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	ps->a[pos] = x; 
}
