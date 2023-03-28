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
void SListInsert(SLTNode** pphead, SLTDataType x);
//删除pos位置的值
void SListErase(SLTNode** pphead, SLTDataType x);
