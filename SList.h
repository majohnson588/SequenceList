#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
typedef struct SListNode
{
	int data;
	struct SListNode* next;
}SLTNode;

SLTNode* BuySListNode(SLTDataType x);
void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** pphead,SLTDataType x);
void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//在pos位置之前插入
void SListInsert(SLTNode** pphead,SLTNode* pos,SLTDataType x);
//删除pos位置的值
void SListErase(SLTNode** pphead, SLTNode* pos);

//考虑在pos之后插入
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//考虑删除pos后面的值
void SListEraseAfter(SLTNode* pos);
