/*
	双向链表先不写了...
	尚未测试，用的时候有问题再修改
*/
#include "CDataStruct.h"

int main(void)
{
	SqList T;
	int a;

	Init_SqList(&T,DATATYPE_CSTRING);
	InsertData_SqList(&T, 0, "aaa");
	InsertData_SqList(&T, 1, "bbb");
	DeleteData_SqList(&T, 0);
	Free_SqList(&T);
}