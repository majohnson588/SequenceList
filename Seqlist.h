#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 200
typedef int SLDataType;

//静态顺序表 -- N太小，可能不够用，N太大，可能浪费空间
typedef struct SeqList
{
	SLDataType* a;  //指向动态数组指针
	int size;       //数据个数
	int capacity;   //容量-空间大小
}SL;

void SLPrint(SL* ps);

void SLPrint(SL* ps);
//增删查改
//void SeqListInit(SL* s)
void SLInit(SL* ps);
void SLDestory(SL* ps);

void SLCheckCapacity(SL* ps);

//头插/头删/尾插/尾删 -- STL
//O(1)
void SLPushBack(SL* ps, SLDataType x);
void SLPopback(SL* ps);

//O(N)
void SLPushFront(SL* ps, SLDataType X);
void SLPopFront(SL* ps);

//任意位置插入删除
void SLInsert(SL* ps,int pos, SLDataType x);
void SLErase(SL* ps, int pos);

//查找和修改
int SLFind(SL* ps, SLDataType x);
int SLModify(SL* ps, SLDataType x);
