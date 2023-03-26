#include "Seqlist.h"

void TestSeqList1()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(&sl);
	SLPushBack(&sl, 5);
	SLPrint(&sl);
	SLInsert(&sl,3,40);
	SLPrint(&sl);
	SLPopFront(&sl);
	SLErase(&sl, 3);
	SLDestory(&sl);
}

int main()
{
	TestSeqList1();

	//越界是不一定报错的
	//系统对越界的检查，设岗抽查
	//int a[10];
	//a[0] = 0;
	////a[10] = 1;
	////a[11] = 1;
	//a[12] = 1;
	//a[15] = 1;

	return 0;
}
