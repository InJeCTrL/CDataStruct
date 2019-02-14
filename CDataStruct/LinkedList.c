/*
	链表（单向、双向）代码实现
*/
#include "LinkedList.h"

int Init_LinkedList(LinkedList L)
{
	L->DataType = DATATYPE_INT;
	L->Data_ptr = NULL;
	L->next = NULL;

	return NO_ERROR;
}
int Clear_LinkedList(LinkedList L)
{
	LinkedListNode *ptr_slow = L->next;//指向首个实节点
	LinkedListNode *ptr_fast = NULL;

	L->next = NULL;
	while (ptr_slow)
	{//循环释放
		free(ptr_slow->Data_ptr);//释放节点指向的数据
		ptr_fast = ptr_slow->next;
		free(ptr_slow);//释放节点
		ptr_slow = ptr_fast;
	}

	return NO_ERROR;
}
int IsEmpty_LinkedList(LinkedList L)
{
	return (L->next ? 0 : 1);
}
long GetLength_LinkedList(LinkedList L)
{
	long len = 0;//链表长度
	LinkedListNode *ptr = L->next;

	while (ptr)
	{
		len++;
		ptr = ptr->next;
	}

	return len;
}
void* GetDataByPos_LinkedList(LinkedList L, long pos)
{
	long t = 0;//临时标记位置序号
	LinkedListNode *ptr = L->next;//节点指针

	while (ptr || pos > t)
	{
		t++;
		ptr = ptr->next;
	}
	if (t != pos || !ptr)
		return ERROR;//越界错误

	return ptr->Data_ptr;
}
void* GetDataByPtr_LinkedList(LinkedListNode *LNode)
{
	return LNode->Data_ptr;
}
long FindPosByData_LinkedList(LinkedList L, void *ptr_Data, int DataType)
{
	long tPos = 0;//待返回位置序号
	LinkedListNode *ptr = L->next;
	
	while (ptr)
	{
		if (DataType == ptr->DataType)
		{//节点内数据类型与给定的数据类型一致
			switch (DataType)
			{
			case DATATYPE_CHAR:
				if (*((char*)ptr->Data_ptr) == *((char*)ptr_Data))
					return tPos;
				break;
			case DATATYPE_DOUBLE:
				if (*((double*)ptr->Data_ptr) == *((double*)ptr_Data))
					return tPos;
				break;
			case DATATYPE_FLOAT:
				if (*((float*)ptr->Data_ptr) == *((float*)ptr_Data))
					return tPos;
				break;
			case DATATYPE_CSTRING:
				if (!strcmp((char*)ptr->Data_ptr, (char*)ptr_Data))
					return tPos;
				break;
			default:
			case DATATYPE_INT:
				if (*((int*)ptr->Data_ptr) == *((int*)ptr_Data))
					return tPos;
				break;
			}
		}
		ptr = ptr->next;
		tPos++;//不一致则寻找下一个
	}

	return ERROR;
}
LinkedListNode* FindPtrByData_LinkedList(LinkedList L, void *ptr_Data, int DataType)
{
	LinkedListNode *ptr = L->next;

	while (ptr)
	{
		if (DataType == ptr->DataType)
		{//节点内数据类型与给定的数据类型一致
			switch (DataType)
			{
			case DATATYPE_CHAR:
				if (*((char*)ptr->Data_ptr) == *((char*)ptr_Data))
					return ptr;
				break;
			case DATATYPE_DOUBLE:
				if (*((double*)ptr->Data_ptr) == *((double*)ptr_Data))
					return ptr;
				break;
			case DATATYPE_FLOAT:
				if (*((float*)ptr->Data_ptr) == *((float*)ptr_Data))
					return ptr;
				break;
			case DATATYPE_CSTRING:
				if (!strcmp((char*)ptr->Data_ptr, (char*)ptr_Data))
					return ptr;
				break;
			default:
			case DATATYPE_INT:
				if (*((int*)ptr->Data_ptr) == *((int*)ptr_Data))
					return ptr;
				break;
			}
		}
		ptr = ptr->next;//不一致则寻找下一个
	}

	return ERROR;
}
void* GetNextData_LinkedList(LinkedListNode *LNode)
{
	return GetDataByPtr_LinkedList(LNode->next);
}
LinkedListNode* GetNextPtr_LinkedList(LinkedListNode *LNode)
{
	return (LNode->next ? LNode->next : ERROR);
}
void* GetPrioData_LinkedList(LinkedList L, LinkedListNode *LNode)
{
	LinkedListNode *ptr = GetPrioPtr_LinkedList(L, LNode);//先获取指向前一个节点的指针

	return (ptr == ERROR ? ERROR : ptr->Data_ptr);//获取节点指针报错则报错，否则返回数据指针
}
LinkedListNode* GetPrioPtr_LinkedList(LinkedList L, LinkedListNode *LNode)
{
	LinkedListNode *ptr = L;

	while (ptr)
	{
		if (L->next == LNode)
			break;//找到前一个节点，或前一个节点是头节点
		ptr = ptr->next;
	}
	if (ptr == L)
		return ERROR;//给出的节点是第一个有效节点

	return ptr;
}
long PtrToPos(LinkedList L, LinkedListNode *LNode)
{
	long tPos = 0;//待返回的位置序号
	LinkedListNode *ptr = L->next;

	while (ptr)
	{
		if (ptr == LNode)
			return tPos;//找到节点
		ptr = ptr->next;
		tPos++;
	}

	return ERROR;
}
LinkedListNode* PosToPtr(LinkedList L, long pos)
{
	long tPos = 0;//临时位置序号
	LinkedListNode *ptr = L->next;

	if (pos < 0)
		return ERROR;//pos越过下界
	while (ptr)
	{
		if (tPos == pos)
			break;
		ptr = ptr->next;
		tPos++;
	}
	
	return (ptr ? ptr : ERROR);
}
LinkedListNode* InsertBefore_LinkedList(LinkedListNode *LNode, void *ptr_Data, int DataType)
{
	LinkedListNode *ptr_NewNode = NULL;//指向插入的新节点
	void *tptr_Data = NULL;//指向待申请的数据

	if (ptr_NewNode = (LinkedListNode*)malloc(sizeof(LinkedListNode)))
	{//成功申请新节点
		//申请数据空间
		switch (DataType)
		{
		case DATATYPE_CHAR:
			tptr_Data = (char*)malloc(sizeof(char));
			break;
		case DATATYPE_DOUBLE:
			tptr_Data = (double*)malloc(sizeof(double));
			break;	
		case DATATYPE_FLOAT:
			tptr_Data = (float*)malloc(sizeof(float));
			break;	
		case DATATYPE_CSTRING:
			tptr_Data = (char*)malloc((strlen(ptr_Data) + 10) * sizeof(char));
			memset(tptr_Data, 0, strlen(ptr_Data) + 10);
			break;
		default:
		case DATATYPE_INT:
			tptr_Data = (int*)malloc(sizeof(int));
			break;
		}
		if (tptr_Data)
		{//成功申请数据空间
			//数据空间赋值
			switch (DataType)
			{
			case DATATYPE_CHAR:
				*((char*)tptr_Data) = *((char*)ptr_Data);
				break;
			case DATATYPE_DOUBLE:
				*((double*)tptr_Data) = *((double*)ptr_Data);
				break;
			case DATATYPE_FLOAT:
				*((float*)tptr_Data) = *((float*)ptr_Data);
				break;
			case DATATYPE_CSTRING:
				strcpy((char*)tptr_Data, (char*)ptr_Data);
				break;
			default:
			case DATATYPE_INT:
				*((int*)tptr_Data) = *((int*)ptr_Data);
				break;
			}
			ptr_NewNode->DataType = LNode->DataType;
			ptr_NewNode->next = LNode->next;
			ptr_NewNode->Data_ptr = LNode->Data_ptr;
			LNode->next = ptr_NewNode;
			LNode->DataType = DataType;
			LNode->Data_ptr = tptr_Data;
			return LNode;
		}
		else
		{
			free(ptr_NewNode);//释放待插入节点
			return ERROR;//申请数据空间失败
		}
	}
	else
		return ERROR;//申请新节点失败
}
LinkedListNode* InsertAfter_LinkedList(LinkedListNode *LNode, void *ptr_Data, int DataType)
{
	LinkedListNode *ptr_NewNode = NULL;//指向插入的新节点
	void *tptr_Data = NULL;//指向待申请的数据

	if (ptr_NewNode = (LinkedListNode*)malloc(sizeof(LinkedListNode)))
	{//成功申请新节点
		//申请数据空间
		switch (DataType)
		{
		case DATATYPE_CHAR:
			tptr_Data = (char*)malloc(sizeof(char));
			break;
		case DATATYPE_DOUBLE:
			tptr_Data = (double*)malloc(sizeof(double));
			break;
		case DATATYPE_FLOAT:
			tptr_Data = (float*)malloc(sizeof(float));
			break;
		case DATATYPE_CSTRING:
			tptr_Data = (char*)malloc((strlen(ptr_Data) + 10) * sizeof(char));
			memset(tptr_Data, 0, strlen(ptr_Data) + 10);
			break;
		default:
		case DATATYPE_INT:
			tptr_Data = (int*)malloc(sizeof(int));
			break;
		}
		if (tptr_Data)
		{//成功申请数据空间
			//数据空间赋值
			switch (DataType)
			{
			case DATATYPE_CHAR:
				*((char*)tptr_Data) = *((char*)ptr_Data);
				break;
			case DATATYPE_DOUBLE:
				*((double*)tptr_Data) = *((double*)ptr_Data);
				break;
			case DATATYPE_FLOAT:
				*((float*)tptr_Data) = *((float*)ptr_Data);
				break;
			case DATATYPE_CSTRING:
				strcpy((char*)tptr_Data, (char*)ptr_Data);
				break;
			default:
			case DATATYPE_INT:
				*((int*)tptr_Data) = *((int*)ptr_Data);
				break;
			}
			ptr_NewNode->next = LNode->next;
			ptr_NewNode->DataType = DataType;
			ptr_NewNode->Data_ptr = tptr_Data;
			LNode->next = ptr_NewNode;
			return ptr_NewNode;
		}
		else
		{
			free(ptr_NewNode);//释放待插入节点
			return ERROR;//申请数据空间失败
		}
	}
	else
		return ERROR;//申请新节点失败

}
int Delete_LinkedList(LinkedList L, LinkedListNode *LNode)
{
	LinkedListNode *ptr = NULL;

	free(LNode->Data_ptr);
	if (LNode->next)
	{//不是尾节点
		LNode->DataType = LNode->next->DataType;
		LNode->Data_ptr = LNode->next->Data_ptr;
		ptr = LNode->next->next;
		free(LNode->next);
		LNode->next = ptr;
	}
	else
	{//是尾节点
		ptr = L;
		while (ptr)
		{
			if (ptr->next == LNode)
			{//找到尾节点前的节点
				free(LNode);
				ptr->next = NULL;
				break;
			}
			else
				ptr = ptr->next;
		}
	}

	return NO_ERROR;
}