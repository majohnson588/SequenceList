#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

//void ListInit(LTNode** pphead)
LTNode* ListInit();
void ListPrint(LTNode* phead);
void ListPushBack(LTNode* phead, LTDataType x);
void ListPushFront(LTNode* phead, LTDataType x);
void ListPopBack(LTNode* phead);
void ListPopFront(LTNode* phead);
bool ListEmpty(LTNode* phead);
//在pos位置之前插入x
void ListInsert(LTNode* pos, LTDataType x);
//删除pos位置的结点
void ListErase(LTNode* pos);
int ListSize(LTNode* phead);
void ListDestory(LTNode* phead);
