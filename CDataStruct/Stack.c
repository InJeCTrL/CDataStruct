/*
	��ʽջ����ʵ��
*/
#include "Stack.h"

int Init_Stack(Stack *S)
{
	S->Length = 0;//��ʼ��ջĿǰ����
	S->StackTop = NULL;//��ʼ��ջ��ָ��

	return Init_LinkedList(&(S->StackData));//��ʼ����ʽջ��������
}
int Clear_Stack(Stack *S)
{
	S->Length = 0;
	S->StackTop = &(S->StackData);

	return Clear_LinkedList(&(S->StackData));
}
int IsEmpty_Stack(Stack *S)
{
	return (S->Length ? 0 : 1);
}
long GetLength_Stack(Stack *S)
{
	return S->Length;
}
int Push_Stack(Stack *S, void *ptr_Data, int DataType)
{
	LinkedListNode *ptr = NULL;//ָ�����Ľڵ�

	ptr = InsertAfter_LinkedList(&(S->StackData), ptr_Data, DataType);
	if (ptr == ERROR)
		return ERROR;//�ڵ����ʧ��
	else
	{//�ڵ����ɹ�
		S->Length++;
		S->StackTop = ptr;
	}

	return NO_ERROR;
}
int Pop_Stack(Stack *S)
{
	if (S->Length == 0)
		return ERROR;//ջ�ѿ�
	Delete_LinkedList(&(S->StackData), S->StackTop);
	S->Length--;
	S->StackTop = S->StackData.next;

	return NO_ERROR;
}
void* GetTopData_Stack(Stack *S)
{
	if (S->Length == 0)
		return ERROR;//ջ�ѿ�
	return S->StackTop->Data_ptr;
}
int GetTopDataType_Stack(Stack *S)
{
	if (S->Length == 0)
		return ERROR;//ջ�ѿ�
	return S->StackTop->DataType;
}