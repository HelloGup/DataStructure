

//栈的作用：
//  //1.需要后进先出的地方（迷宫问题：走错后坐标依次出栈 实现后退）
//      //2.递归改成非递归


#include "stack.h"


//初始化
void InitStack(Stack* st){
    st->_data=(STDataType*)malloc(sizeof(STDataType)*4);
    if(st->_data==NULL){
        printf("初始化失败\n");
        exit(-1);
    }

    st->_capacity=4;
    st->_top=0;
}

//入栈
void StackPush(Stack* st,STDataType data){
    assert(st);

    //检查容量
    if(st->_top==st->_capacity){

        //使用临时变量 防止开辟失败破坏原数据
        STDataType* tmp=(STDataType*)realloc(st->_data,sizeof(STDataType)*st->_capacity*2);
        if(tmp==NULL){
            printf("增容失败\n");
            exit(-1);
        }

        st->_data=tmp;
        st->_capacity*=2;
    }

    //插入数据
    st->_data[st->_top++]=data;
}

//出栈
void StackPop(Stack* st){
    assert(st);
    //assert(st->_top>0);
    if(st->_top>0)
        st->_top--;
}

//返回栈顶数据
STDataType StackTop(Stack* st){
    assert(st);
    assert(st->_top>0);

    return st->_data[st->_top-1];
}

//获取栈中有效元素个数
int StackSize(Stack* st){
    assert(st);

    return st->_top;
}

//判断栈是否为空栈
int StackEmpty(Stack* st){
    assert(st);

    return st->_top==0?1:0;
}

//销毁栈
void StackDestroy(Stack* st){
    assert(st);

    free(st->_data);
    st->_data=NULL;
    st->_top=st->_capacity=0;
}

//打印
void StackPrint(Stack* st){
    assert(st);

    int i=0;
    for(i=0;i<st->_top;i++){
        printf("%d ",st->_data[i]);
    }
    printf("\n");
}
