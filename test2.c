#include "SList.h"

void TestSList1()
{
	//struct SListNode*
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n1);

	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n2);

	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n3);

	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n4);

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	SLTNode* plist = n1;
	SListPrint(plist);

	SListPushBack(&plist, 5);
	SListPushBack(&plist, 6);
	SListPushBack(&plist, 7);
	SListPushBack(&plist, 8);
	SListPrint(plist);

	SLTNode* ret = SListFind(plist, 3);
	if (ret)
	{
		printf("找到了\n");
		ret->data = 30;
	}
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 4);
	if (pos)
	{
		SListErase(&plist, pos);
	}
	SListPrint(plist);
}

void TestSList2()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);
	SListPushFront(&plist, 0);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
}

int main()
{
	TestSList1();
	TestSList2();
	return 0;
}
