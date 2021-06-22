#include "SeqList.h"

//初始化顺序表
void InitSeqList(SeqList* ps) {
	assert(ps);

	//开辟数据地址指向的空间
	ps->data = (SeqListDataType*)malloc(sizeof(SeqListDataType) * 4);
	if (ps->data == NULL) {
		printf("申请内存失败\n");
		exit(-1);//强制退出程序
	}

	//更新容量 大小
	ps->capacity = 4;
	ps->size = 0;
}

//检查容量
void SeqListCheakCapacity(SeqList* ps) {

	assert(ps);

	//检查是否需要扩容
	if (ps->capacity == ps->size) {
		ps->data = (SeqListDataType*)realloc(ps->data, sizeof(SeqListDataType) * ps->capacity * 2);
		if (ps->data == NULL) {
			printf("增容失败\n");
			exit(-1);
		}
		//更新容量
		ps->capacity *= 2;
	}
}

//尾插
void SeqListPushBack(SeqList* ps, SeqListDataType data) {

	SeqListInsert(ps, ps->size, data);
}

//尾删
void SeqListPopBack(SeqList* ps) {

	SeqListErase(ps, ps->size - 1);
}

//头插
void SeqListPushFront(SeqList* ps, SeqListDataType data) {

	SeqListInsert(ps, 0, data);
}

//头删
void SeqListPopFront(SeqList* ps) {

	SeqListErase(ps, 0);
}

//指定位置插入
void SeqListInsert(SeqList* ps, int pos, SeqListDataType data) {
	assert(ps);
	//尾插时pos==size
	assert(pos <= ps->size && pos >= 0);

	SeqListCheakCapacity(ps);

	//后移数据
	int index = ps->size - 1;
	while (index >= pos) {
		ps->data[index + 1] = ps->data[index];
		index--;
	}

	//插入数据 更新大小
	ps->data[pos] = data;
	ps->size++;
}

//指定位置删除
void SeqListErase(SeqList* ps, int pos) {
	assert(ps);
	if (pos < 0 || pos >= ps->size) {
		return;
	}

	//前移数据
	int index = pos;
	while (index < ps->size - 1) {
		ps->data[index] = ps->data[index + 1];
		index++;
	}

	//更新大小
	ps->size--;
}

//查找
int SeqListFind(SeqList* ps, SeqListDataType data) {
	assert(ps);

	//遍历查找
	int i=0;
    for (i = 0; i < ps->size; i++) {
		if (ps->data[i] == data) {
			//找到返回下标
			return i;
		}
	}
	return -1;
}

//打印
void SeqListPrint(SeqList* ps) {
	assert(ps);

	if (ps->size == 0) {
		return;
	}

	int index = 0;
	while (index < ps->size) {
		printf("%d ", ps->data[index]);
		index++;
	}
	printf("\n");
}

//销毁顺序表
void SeqListDestroy(SeqList* ps) {
	assert(ps);

	//释放data空间
	free(ps->data);
	ps->data = NULL;

	ps->capacity = 0;
	ps->size = 0;
}

