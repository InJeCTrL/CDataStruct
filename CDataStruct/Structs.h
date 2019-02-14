#pragma once
#include <malloc.h>
#include <string.h>

#define NO_ERROR			0	//�������÷���
#define ERROR				-1	//���ִ���

#define DATATYPE_INT		0	//������������
#define DATATYPE_LONG		1	//��������������
#define DATATYPE_FLOAT		2	//�����ȸ�������������
#define DATATYPE_DOUBLE		3	//˫���ȸ�����������
#define DATATYPE_CHAR		4	//�ַ�����������
#define DATATYPE_CSTRING	5	//C�ַ�������������

//˳���
typedef struct
{
	void *DataList;//��������
	long length;//��ǰ˳�����
	long size;//˳����ܳ���
	int DataType;//��������
}SqList;

//��������
typedef struct LinkedListNode
{
	void *Data_ptr;//������ָ��
	struct LinkedListNode *next;//���ָ����
	int DataType;//��������,ÿ���ڵ���������Ϳ��Բ�һ��
}LinkedListNode, *LinkedList;

//˫������
typedef struct DLinkedListNode
{
	void *Data_ptr;//������ָ��
	struct DLinkedListNode *prev, *next;//ǰ�������ָ����
	int DataType;//��������,ÿ���ڵ���������Ϳ��Բ�һ��
}DLinkedListNode, *DLinkedList;

//��ʽջ
typedef struct
{
	LinkedListNode StackData;//ջ�������ͷ�ڵ㣨��������
	LinkedListNode *StackTop;//ָ��ջ����ָ��
	long Length;//��ǰջ������
}Stack;

//��ʽ����
typedef struct
{
	LinkedListNode QueueData;//�����������ͷ�ڵ㣨��������
	LinkedListNode *QueueHead, *QueueTail;//ָ�����ͷ��β��ָ��
	long Length;//��ǰ���е�����
}Queue;