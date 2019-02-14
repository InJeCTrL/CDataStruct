/*
	链式栈代码实现
*/
#include "Stack.h"

int Init_Stack(Stack *S)
{
	S->Length = 0;//初始化栈目前容量
	S->StackTop = NULL;//初始化栈顶指针

	return Init_LinkedList(&(S->StackData));//初始化链式栈的数据区
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
	LinkedListNode *ptr = NULL;//指向插入的节点

	ptr = InsertAfter_LinkedList(&(S->StackData), ptr_Data, DataType);
	if (ptr == ERROR)
		return ERROR;//节点插入失败
	else
	{//节点插入成功
		S->Length++;
		S->StackTop = ptr;
	}

	return NO_ERROR;
}
int Pop_Stack(Stack *S)
{
	if (S->Length == 0)
		return ERROR;//栈已空
	Delete_LinkedList(&(S->StackData), S->StackTop);
	S->Length--;
	S->StackTop = S->StackData.next;

	return NO_ERROR;
}
void* GetTopData_Stack(Stack *S)
{
	if (S->Length == 0)
		return ERROR;//栈已空
	return S->StackTop->Data_ptr;
}
int GetTopDataType_Stack(Stack *S)
{
	if (S->Length == 0)
		return ERROR;//栈已空
	return S->StackTop->DataType;
}