/*
	˫�������Ȳ�д��...
	��δ���ԣ��õ�ʱ�����������޸�
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