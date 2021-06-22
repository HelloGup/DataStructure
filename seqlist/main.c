#include "SeqList.h"

int main() {
	SeqList s;

	InitSeqList(&s);
	//测试尾插
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);

	//测试头插
	SeqListPushFront(&s,88);
	SeqListPrint(&s);

	//测试尾删
	SeqListPopBack(&s);

	//测试头删
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	//测试查找
	int index=SeqListFind(&s, 5);
	if (index != -1) {
		s.data[index] = 55;
	}

	printf("查找到的索引是：%d\n",index);
	SeqListPrint(&s);

	//销毁
	SeqListDestroy(&s);
	
    return 0;
}
