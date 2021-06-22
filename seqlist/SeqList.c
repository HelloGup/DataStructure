#include "SeqList.h"

//��ʼ��˳���
void InitSeqList(SeqList* ps) {
	assert(ps);

	//�������ݵ�ַָ��Ŀռ�
	ps->data = (SeqListDataType*)malloc(sizeof(SeqListDataType) * 4);
	if (ps->data == NULL) {
		printf("�����ڴ�ʧ��\n");
		exit(-1);//ǿ���˳�����
	}

	//�������� ��С
	ps->capacity = 4;
	ps->size = 0;
}

//�������
void SeqListCheakCapacity(SeqList* ps) {

	assert(ps);

	//����Ƿ���Ҫ����
	if (ps->capacity == ps->size) {
		ps->data = (SeqListDataType*)realloc(ps->data, sizeof(SeqListDataType) * ps->capacity * 2);
		if (ps->data == NULL) {
			printf("����ʧ��\n");
			exit(-1);
		}
		//��������
		ps->capacity *= 2;
	}
}

//β��
void SeqListPushBack(SeqList* ps, SeqListDataType data) {

	SeqListInsert(ps, ps->size, data);
}

//βɾ
void SeqListPopBack(SeqList* ps) {

	SeqListErase(ps, ps->size - 1);
}

//ͷ��
void SeqListPushFront(SeqList* ps, SeqListDataType data) {

	SeqListInsert(ps, 0, data);
}

//ͷɾ
void SeqListPopFront(SeqList* ps) {

	SeqListErase(ps, 0);
}

//ָ��λ�ò���
void SeqListInsert(SeqList* ps, int pos, SeqListDataType data) {
	assert(ps);
	//β��ʱpos==size
	assert(pos <= ps->size && pos >= 0);

	SeqListCheakCapacity(ps);

	//��������
	int index = ps->size - 1;
	while (index >= pos) {
		ps->data[index + 1] = ps->data[index];
		index--;
	}

	//�������� ���´�С
	ps->data[pos] = data;
	ps->size++;
}

//ָ��λ��ɾ��
void SeqListErase(SeqList* ps, int pos) {
	assert(ps);
	if (pos < 0 || pos >= ps->size) {
		return;
	}

	//ǰ������
	int index = pos;
	while (index < ps->size - 1) {
		ps->data[index] = ps->data[index + 1];
		index++;
	}

	//���´�С
	ps->size--;
}

//����
int SeqListFind(SeqList* ps, SeqListDataType data) {
	assert(ps);

	//��������
	int i=0;
    for (i = 0; i < ps->size; i++) {
		if (ps->data[i] == data) {
			//�ҵ������±�
			return i;
		}
	}
	return -1;
}

//��ӡ
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

//����˳���
void SeqListDestroy(SeqList* ps) {
	assert(ps);

	//�ͷ�data�ռ�
	free(ps->data);
	ps->data = NULL;

	ps->capacity = 0;
	ps->size = 0;
}

