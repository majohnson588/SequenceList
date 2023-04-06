#include "List.h"

LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void ListPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = BuyListNode(x);
	LTNode* next = phead->next;

	// phead newnode next
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = next;
	next->prev = newnode;
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;
	 
	free(tail);

	tailPrev->next = phead;
	phead -> prev = tailPrev;
}

bool ListEmpty(LTNode* phead)
{
	assert(phead);

	return phead->next == phead;
}

//在pos位置之前插入x
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);

	// prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

//删除pos位置的结点
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(!ListEmpty(phead));

	ListErase(phead);
}

int ListSize(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	int size = 0;
	while (cur != phead)
	{
		++size;
		cur = cur->next;
	}

	return size;
}

void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	int size = 0;
	while (cur != head)
	{
		LTNode* next = cur->next;
		ListErase(cur);
		cur = next;
	}

	free(phead);
	phead = NULL;
}
