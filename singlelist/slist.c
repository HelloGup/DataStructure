#include "slist.h"


// 动态申请一个节点
SListNode* BuySListNode(SLDataType x){
    
    SListNode* newNode=(SListNode*)malloc(sizeof(SListNode));
    if(newNode==NULL){
        printf("创建结点失败\n");
        exit(-1);
    }

    newNode->_next=NULL;
    newNode->_data=x;
    return newNode;
}


//单链表打印
void SListPrint(SListNode* plist){
    SListNode* cur=plist;

    while(cur){
        printf("%d-> ",cur->_data);
        cur=cur->_next;
    }
    printf("NULL\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLDataType x){
    SListNode* newNode= BuySListNode(x);   

    if(*pplist==NULL){
        *pplist=newNode;
        return;
    }

    SListNode* tail=*pplist;
    while(tail->_next!=NULL){
        tail=tail->_next;
    }

    tail->_next=newNode;
}


// 单链表的头插
void SListPushFront(SListNode** pplist, SLDataType x){
    SListNode* newNode= BuySListNode(x);   

    newNode->_next=*pplist;
    *pplist=newNode;
}
// 单链表的尾删
void SListPopBack(SListNode** pplist){
    if(*pplist==NULL){
        return ;
    }

    else if((*pplist)->_next==NULL){
        free(*pplist);
        *pplist=NULL;
    }
    else{
        SListNode* tail=*pplist;
        SListNode* prev=NULL;

        while(tail->_next!=NULL){
            prev=tail;
            tail=tail->_next;
        }
        free(tail);
        prev->_next=NULL;
    }
}

// 单链表头删
void SListPopFront(SListNode** pplist){
    if(*pplist==NULL){
        return;
    }
    else if((*pplist)->_next==NULL){
        free(*pplist);
        *pplist=NULL;
    }
    else{
        SListNode* next=(*pplist)->_next;
        free(*pplist);
        *pplist=next;
    }
}
// 单链表查找
SListNode* SListFind(SListNode* pplist, SLDataType x){
    if(pplist==NULL){
        return NULL;
    }

    SListNode* cur=pplist;
    while(cur){
        if(cur->_data==x){
            return cur;
        }
        cur=cur->_next;
    }
    return NULL;
}

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLDataType x){
    assert(pos);

    SListNode* newNode=BuySListNode(x);
    newNode->_next=pos->_next;
    pos->_next=newNode;
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos){
    if(pos==NULL){
        return;
    }

    if(pos->_next!=NULL){
        SListNode* next=pos->_next;
        SListNode* nextnext=next->_next;
        //SListNode* nextnext=pos->_next->_next;
        free(next);
        pos->_next=nextnext;
    }
}

void DestorySList(SListNode** pplist){
    SListNode* cur=*pplist;
    
    while(cur){
        SListNode* next=cur->_next;

        free(cur);
        cur=next;
    }
    *pplist=NULL;
}
