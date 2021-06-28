#include "stack.h"

void Test(){
    Stack st;
    InitStack(&st);
    
    printf("测试入栈\n");
    StackPush(&st,1);
    StackPush(&st,2);
    StackPush(&st,3);
    StackPush(&st,4);
    printf("栈中数据个数：%d\n",StackSize(&st));
    StackPrint(&st);

    printf("测试出栈\n");
    StackPop(&st);
    printf("栈中数据个数：%d 是否空栈：%d\n",StackSize(&st),StackEmpty(&st));
    StackPrint(&st);
    StackPop(&st);
    printf("栈中数据个数：%d 是否空栈：%d\n",StackSize(&st),StackEmpty(&st));
    StackPrint(&st);
    StackPop(&st);
    printf("栈中数据个数：%d 是否空栈：%d\n",StackSize(&st),StackEmpty(&st));
    StackPrint(&st);
    StackPop(&st);
    printf("栈中数据个数：%d 是否空栈：%d\n",StackSize(&st),StackEmpty(&st));
    StackPrint(&st);
    StackPop(&st);
    printf("栈中数据个数：%d 是否空栈：%d\n",StackSize(&st),StackEmpty(&st));
    StackPrint(&st);
    StackPop(&st);
    printf("栈中数据个数：%d 是否空栈：%d\n",StackSize(&st),StackEmpty(&st));
    StackPrint(&st);
    StackPop(&st);
    printf("栈中数据个数：%d 是否空栈：%d\n",StackSize(&st),StackEmpty(&st));
    StackPrint(&st);

    StackDestroy(&st);
}

int main(){
    Test();
    return 0;
}
