/*
	��������˫�򣩴���ʵ��
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
	LinkedListNode *ptr_slow = L->next;//ָ���׸�ʵ�ڵ�
	LinkedListNode *ptr_fast = NULL;

	L->next = NULL;
	while (ptr_slow)
	{//ѭ���ͷ�
		free(ptr_slow->Data_ptr);//�ͷŽڵ�ָ�������
		ptr_fast = ptr_slow->next;
		free(ptr_slow);//�ͷŽڵ�
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
	long len = 0;//������
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
	long t = 0;//��ʱ���λ�����
	LinkedListNode *ptr = L->next;//�ڵ�ָ��

	while (ptr || pos > t)
	{
		t++;
		ptr = ptr->next;
	}
	if (t != pos || !ptr)
		return ERROR;//Խ�����

	return ptr->Data_ptr;
}
void* GetDataByPtr_LinkedList(LinkedListNode *LNode)
{
	return LNode->Data_ptr;
}
long FindPosByData_LinkedList(LinkedList L, void *ptr_Data, int DataType)
{
	long tPos = 0;//������λ�����
	LinkedListNode *ptr = L->next;
	
	while (ptr)
	{
		if (DataType == ptr->DataType)
		{//�ڵ��������������������������һ��
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
		tPos++;//��һ����Ѱ����һ��
	}

	return ERROR;
}
LinkedListNode* FindPtrByData_LinkedList(LinkedList L, void *ptr_Data, int DataType)
{
	LinkedListNode *ptr = L->next;

	while (ptr)
	{
		if (DataType == ptr->DataType)
		{//�ڵ��������������������������һ��
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
		ptr = ptr->next;//��һ����Ѱ����һ��
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
	LinkedListNode *ptr = GetPrioPtr_LinkedList(L, LNode);//�Ȼ�ȡָ��ǰһ���ڵ��ָ��

	return (ptr == ERROR ? ERROR : ptr->Data_ptr);//��ȡ�ڵ�ָ�뱨���򱨴����򷵻�����ָ��
}
LinkedListNode* GetPrioPtr_LinkedList(LinkedList L, LinkedListNode *LNode)
{
	LinkedListNode *ptr = L;

	while (ptr)
	{
		if (L->next == LNode)
			break;//�ҵ�ǰһ���ڵ㣬��ǰһ���ڵ���ͷ�ڵ�
		ptr = ptr->next;
	}
	if (ptr == L)
		return ERROR;//�����Ľڵ��ǵ�һ����Ч�ڵ�

	return ptr;
}
long PtrToPos(LinkedList L, LinkedListNode *LNode)
{
	long tPos = 0;//�����ص�λ�����
	LinkedListNode *ptr = L->next;

	while (ptr)
	{
		if (ptr == LNode)
			return tPos;//�ҵ��ڵ�
		ptr = ptr->next;
		tPos++;
	}

	return ERROR;
}
LinkedListNode* PosToPtr(LinkedList L, long pos)
{
	long tPos = 0;//��ʱλ�����
	LinkedListNode *ptr = L->next;

	if (pos < 0)
		return ERROR;//posԽ���½�
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
	LinkedListNode *ptr_NewNode = NULL;//ָ�������½ڵ�
	void *tptr_Data = NULL;//ָ������������

	if (ptr_NewNode = (LinkedListNode*)malloc(sizeof(LinkedListNode)))
	{//�ɹ������½ڵ�
		//�������ݿռ�
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
		{//�ɹ��������ݿռ�
			//���ݿռ丳ֵ
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
			free(ptr_NewNode);//�ͷŴ�����ڵ�
			return ERROR;//�������ݿռ�ʧ��
		}
	}
	else
		return ERROR;//�����½ڵ�ʧ��
}
LinkedListNode* InsertAfter_LinkedList(LinkedListNode *LNode, void *ptr_Data, int DataType)
{
	LinkedListNode *ptr_NewNode = NULL;//ָ�������½ڵ�
	void *tptr_Data = NULL;//ָ������������

	if (ptr_NewNode = (LinkedListNode*)malloc(sizeof(LinkedListNode)))
	{//�ɹ������½ڵ�
		//�������ݿռ�
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
		{//�ɹ��������ݿռ�
			//���ݿռ丳ֵ
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
			free(ptr_NewNode);//�ͷŴ�����ڵ�
			return ERROR;//�������ݿռ�ʧ��
		}
	}
	else
		return ERROR;//�����½ڵ�ʧ��

}
int Delete_LinkedList(LinkedList L, LinkedListNode *LNode)
{
	LinkedListNode *ptr = NULL;

	free(LNode->Data_ptr);
	if (LNode->next)
	{//����β�ڵ�
		LNode->DataType = LNode->next->DataType;
		LNode->Data_ptr = LNode->next->Data_ptr;
		ptr = LNode->next->next;
		free(LNode->next);
		LNode->next = ptr;
	}
	else
	{//��β�ڵ�
		ptr = L;
		while (ptr)
		{
			if (ptr->next == LNode)
			{//�ҵ�β�ڵ�ǰ�Ľڵ�
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