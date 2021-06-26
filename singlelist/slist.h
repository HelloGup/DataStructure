#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SListNode{
    SLDataType _data;
    struct SListNode* _next;
}SListNode;

// 动态申请一个节点
SListNode* BuySListNode(SLDataType x);
//单链表打印
void SListPrint(SListNode* plist);
// 单链表尾插
void SListPushBack(SListNode** pplist, SLDataType x);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLDataType x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表头删
void SListPopFront(SListNode** pplist);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLDataType x);

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLDataType x);

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);

//销毁
void DestorySList(SListNode** pplist);
