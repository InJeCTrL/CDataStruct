/*
	链式队列代码实现
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
		return ERROR;//入队失败
	Q->QueueTail = ptr;
	if (Q->Length == 0)
		Q->QueueHead = Q->QueueData.next;//入队前队列为空
	Q->Length++;

	return NO_ERROR;
}
int Pull_Queue(Queue *Q)
{
	if (Q->Length == 0)
		return ERROR;//队列空
	Q->Length--;
	Delete_LinkedList(&(Q->QueueData), Q->QueueHead);
	if (!Q->Length)
	{//本次出队后队列空
		Q->QueueHead = &(Q->QueueData);
		Q->QueueTail = Q->QueueHead;
	}
	else
		Q->QueueHead = Q->QueueData.next;//本次出队后队列仍有数据

	return NO_ERROR;
}
void* GetHeadData_Queue(Queue *Q)
{
	if (Q->Length == 0)
		return ERROR;//队列已空
	return Q->QueueHead->Data_ptr;
}
int GetHeadDataType_Queue(Queue *Q)
{
	if (Q->Length == 0)
		return ERROR;//队列已空
	return Q->QueueHead->DataType;
}