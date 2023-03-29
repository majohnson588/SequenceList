#include "SList.h"

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾结点
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPopBack(SLTNode** pphead)
{
	assert(*pphead != NULL);

	//1.只有一个结点
	//2.多个结点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//SLTNode* tailPrev = NULL;
		//SLTNode* tail = *pphead;
		//while (tail->next != NULL)
		//{
		//	tailPrev = tail;
		//	tail = tail->next;
		//}
		//free(tail);
		//tailPrev->next = NULL;
		SLTNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SListPopFront(SLTNode** pphead)
{
	assert(*pphead != NULL);
	//release会忽略ASSERT
	//if (*pphead == NULL)
	//	return;
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
			return cur;

		cur = cur->next;
	}

	return NULL;
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	//头插
	if(pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		SLTNode* newnode = BuySListNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}

void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);

	if (*pphead == pos)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
	}
}

void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	//SLTNode* newnode = BuySlistNode(x);
	//newnode->next = pos->next;
	//pos->next = newnode;

	//不在乎链表顺序
	SLTNode* newnode = BuySListNode(x);
	SLTNode* next = pos->next;
	//将next作为tmp存起来
	pos->next = newnode;
	newnode->next = next;
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);

	if (pos->next == NULL)
		return;

	SLTNode* del = pos->next;
	//pos->next = pos->next->next;代码没问题，但是没法释放
	pos->next = del->next;
	free(del);
	del = NULL;
}
