/*
	˳���
*/
#pragma once
#include "Structs.h"

//��ʼ��˳���ָ��˳����ָ��,����˵��(�ο���DATATYPE_*)��
//��ʼsize����20
int Init_SqList(SqList*, int);
//�ͷ�˳���ָ��˳����ָ�룩
int Free_SqList(SqList*);
//���˳������������ָ��˳����ָ�룩
int Clear_SqList(SqList*);
//�ж�˳����Ƿ�Ϊ�գ�ָ��˳����ָ�룩
int IsEmpty_SqList(SqList*);
//��ȡ˳������������Ч���ȣ�ָ��˳����ָ�룩
long GetLength_SqList(SqList*);
//��ȡ˳���ָ��λ�õ����ݣ�ָ��˳����ָ��,��������ָ��λ�ã�
//����ERROR��ʾδ�ҵ�����ERROR��Ϊָ�����ݵ�ָ��
void* GetData_SqList(SqList*, long);
//��ȡָ��������˳����е�λ�ã�ָ��˳����ָ��,ָ�����ݵ�ָ�룩
//����ERROR��ʾδ�ҵ�����ERROR��Ϊ����λ��
long FindDataPos_SqList(SqList*, void*);
//��ȡ��������ָ��λ��֮��һλ�����ݣ�ָ��˳����ָ��,��������ָ��λ�ã�
//����ERROR��ʾδ�ҵ�����ERROR��Ϊָ�����ݵ�ָ��
void* GetNextData_SqList(SqList*, long);
//��ȡ��������ָ��λ��֮ǰһλ�����ݣ�ָ��˳����ָ��,��������ָ��λ�ã�
//����ERROR��ʾδ�ҵ�����ERROR��Ϊָ�����ݵ�ָ��
void* GetPrioData_SqList(SqList*, long);
//�ڸ���λ��֮ǰ�������ݣ�ָ��˳����ָ��,��������ָ��λ��,ָ����������ݵ�ָ�룩
//����ERROR��ʾ����ʧ�ܣ���ERROR��Ϊ�����λ��
long InsertData_SqList(SqList*, long, void*);
//ɾ������λ�õ����ݣ�ָ��˳����ָ��,��������ָ��λ�ã�
int DeleteData_SqList(SqList*, long);