/*
	ջ����ʽջ��
*/
#pragma once
#include "Structs.h"
#include "LinkedList.h"

//��ʼ����ʽջ��ָ��ջ�ṹ��ָ�룩
int Init_Stack(Stack*);
//�����ʽջ,ջ�Կ�ʹ�ã�ָ��ջ�ṹ��ָ�룩
int Clear_Stack(Stack*);
//�ж���ʽջ�Ƿ�Ϊ�գ�ָ��ջ�ṹ��ָ�룩
int IsEmpty_Stack(Stack*);
//��ȡ���еĳ��ȣ�ָ��ջ�ṹ��ָ�룩
long GetLength_Stack(Stack*);
//����ջѹջ��ָ��ջ�ṹ��ָ��,ָ�����ݵ�ָ��,����˵��(�ο���DATATYPE_*)��
//����ERROR��ʾ��ջʧ�ܣ�����ʧ�ܣ�����ERROR��Ϊ�ɹ���ջ
int Push_Stack(Stack*, void*, int);
//��ջ��ջ��ָ��ջ�ṹ��ָ�룩
//����ERROR��ʾ��ջʧ�ܣ�ջ�ѿգ�����ERROR��Ϊ�ɹ���ջ
int Pop_Stack(Stack*);
//��ȡ��ʽջջ������ָ�루ָ��ջ�ṹ��ָ�룩
//����ERROR��ʾջ�ѿգ���ERROR��Ϊջ������ָ��
void* GetTopData_Stack(Stack*);
//��ȡ��ʽջջ�����ݵ��������ͣ�ָ��ջ�ṹ��ָ�룩
//����ERROR��ʾջ�ѿգ���ERROR��Ϊջ����������
int GetTopDataType_Stack(Stack*);