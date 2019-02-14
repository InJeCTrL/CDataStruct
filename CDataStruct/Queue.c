/*
	��ʽ���д���ʵ��
*/
#include "Queue.h"

int Init_Queue(Queue *Q)
{
	Init_LinkedList(&(Q->QueueData));
	Q->Length = 0;
	Q->QueueTail = &(Q->QueueData);
	Q->QueueHead = Q->QueueTail;
	
	return NO_ERROR;
}
int Clear_Queue(Queue *Q)
{
	Clear_LinkedList(&(Q->QueueData));
	Q->Length = 0;
	Q->QueueTail = &(Q->QueueData);
	Q->QueueHead = Q->QueueTail;

	return NO_ERROR;
}
int IsEmpty_Queue(Queue *Q)
{
	return (Q->Length ? 0 : 1);
}
long GetLength_Queue(Queue *Q)
{
	return Q->Length;
}
int Push_Queue(Queue *Q, void *ptr_Data, int DataType)
{
	LinkedListNode *ptr = NULL;

	ptr = InsertAfter_LinkedList(Q->QueueTail, ptr_Data, DataType);
	if (ptr == ERROR)
		return ERROR;//���ʧ��
	Q->QueueTail = ptr;
	if (Q->Length == 0)
		Q->QueueHead = Q->QueueData.next;//���ǰ����Ϊ��
	Q->Length++;

	return NO_ERROR;
}
int Pull_Queue(Queue *Q)
{
	if (Q->Length == 0)
		return ERROR;//���п�
	Q->Length--;
	Delete_LinkedList(&(Q->QueueData), Q->QueueHead);
	if (!Q->Length)
	{//���γ��Ӻ���п�
		Q->QueueHead = &(Q->QueueData);
		Q->QueueTail = Q->QueueHead;
	}
	else
		Q->QueueHead = Q->QueueData.next;//���γ��Ӻ������������

	return NO_ERROR;
}
void* GetHeadData_Queue(Queue *Q)
{
	if (Q->Length == 0)
		return ERROR;//�����ѿ�
	return Q->QueueHead->Data_ptr;
}
int GetHeadDataType_Queue(Queue *Q)
{
	if (Q->Length == 0)
		return ERROR;//�����ѿ�
	return Q->QueueHead->DataType;
}