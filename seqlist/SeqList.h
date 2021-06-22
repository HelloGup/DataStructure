#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SeqListDataType;

//顺序表结构体
typedef struct SeqList {
	SeqListDataType* data;
	int capacity;
	int size;
}SeqList;

//初始化
void InitSeqList(SeqList* ps);

//打印
void SeqListPrint(SeqList* ps);

//尾插
void SeqListPushBack(SeqList* ps, SeqListDataType data);

//尾删
void SeqListPopBack(SeqList* ps);

//头插
void SeqListPushFront(SeqList* ps, SeqListDataType data);

//头删
void SeqListPopFront(SeqList* ps);

//指定位置插入
void SeqListInsert(SeqList* ps, int pos, SeqListDataType data);

//指定位置删除
void SeqListErase(SeqList* ps, int pos);

//查找
int SeqListFind(SeqList* ps, SeqListDataType data);

//销毁顺序表
void SeqListDestroy(SeqList* ps);