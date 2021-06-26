#include "slist.h"

void Test(){
    SListNode* sp=NULL;
    SListPushBack(&sp,1);
    SListPrint(sp);

    SListPushFront(&sp,2);
    SListPushFront(&sp,3);
    SListPushBack(&sp,4);
    SListPushBack(&sp,5);
    SListPushBack(&sp,6);
    SListPrint(sp);

    SListPopBack(&sp);
    SListPopFront(&sp);
    SListPrint(sp);

    SListNode* ret= SListFind(sp,2);
    if(ret){
        SListInsertAfter(ret,88);
    }

    SListNode* ret1= SListFind(sp,4);
    if(ret){
        SListEraseAfter(ret1);
    }
    SListPrint(sp);
    SListPopBack(&sp);
    SListPopBack(&sp);
    SListPopBack(&sp);
    SListPopBack(&sp);
    SListPopBack(&sp);
    SListPopBack(&sp);
    SListPopBack(&sp);
    SListPrint(sp);

    DestorySList(&sp);
}

int main(){

    Test();
    return 0;

}

