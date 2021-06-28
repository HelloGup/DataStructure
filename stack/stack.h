#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;

//声明栈结构体
typedef struct Stack{
    int* _data;
    int _top;
    int _capacity;
}Stack;

//初始化
void InitStack(Stack* st);

//入栈
void StackPush(Stack* st,STDataType data);

//出栈
void StackPop(Stack* st);

//返回栈顶数据
STDataType StackTop(Stack* st);

//获取栈中有效元素个数
int StackSize(Stack* st);

//判断栈是否为空栈
int StackEmpty(Stack* st);

//销毁栈
void StackDestroy(Stack* st);

//打印
void StackPrint(Stack* st);
