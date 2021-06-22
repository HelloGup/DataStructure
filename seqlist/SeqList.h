#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SeqListDataType;

//˳���ṹ��
typedef struct SeqList {
	SeqListDataType* data;
	int capacity;
	int size;
}SeqList;

//��ʼ��
void InitSeqList(SeqList* ps);

//��ӡ
void SeqListPrint(SeqList* ps);

//β��
void SeqListPushBack(SeqList* ps, SeqListDataType data);

//βɾ
void SeqListPopBack(SeqList* ps);

//ͷ��
void SeqListPushFront(SeqList* ps, SeqListDataType data);

//ͷɾ
void SeqListPopFront(SeqList* ps);

//ָ��λ�ò���
void SeqListInsert(SeqList* ps, int pos, SeqListDataType data);

//ָ��λ��ɾ��
void SeqListErase(SeqList* ps, int pos);

//����
int SeqListFind(SeqList* ps, SeqListDataType data);

//����˳���
void SeqListDestroy(SeqList* ps);