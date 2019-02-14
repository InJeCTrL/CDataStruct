/*
	��������˫��
*/
#pragma once
#include "Structs.h"

//��ʼ����������ָ��������ͷ�ڵ��ָ�룩
int Init_LinkedList(LinkedList);
//��յ�������,ֻ����ͷ�ڵ㣨ָ��������ͷ�ڵ��ָ�룩
int Clear_LinkedList(LinkedList);
//�жϵ��������Ƿ�Ϊ�գ�ָ��������ͷ�ڵ��ָ�룩
int IsEmpty_LinkedList(LinkedList);
//��ȡ��������ĳ��ȣ�ָ��������ͷ�ڵ��ָ�룩
long GetLength_LinkedList(LinkedList);
//����λ����Ż�ȡ��������ָ��λ�õ����ݣ�ָ��������ͷ�ڵ��ָ��,λ����ţ�
//����ERROR��ʾδ�ҵ�����ERROR��Ϊָ�����ݵ�ָ��
void* GetDataByPos_LinkedList(LinkedList, long);
//���ݽڵ�ָ���ȡ��������ָ��λ�õ����ݣ�ָ��������ĳ�ڵ��ָ�룩
void* GetDataByPtr_LinkedList(LinkedListNode*);
//��ȡָ�������ڵ��������е�λ�ã�ָ��������ͷ�ڵ��ָ��,ָ�����ݵ�ָ��,����������˵��(�ο���DATATYPE_*)��
//����ERROR��ʾδ�ҵ�����ERROR��Ϊλ�����
long FindPosByData_LinkedList(LinkedList, void*, int);
//��ȡָ��ָ�����ݽڵ��ָ�루ָ��������ͷ�ڵ��ָ��,ָ�����ݵ�ָ��,����������˵��(�ο���DATATYPE_*)��
//����ERROR��ʾδ�ҵ�����ERROR��Ϊ�ڵ�ָ��
LinkedListNode* FindPtrByData_LinkedList(LinkedList, void*, int);
//��ȡ����������ָ���ڵ�ĺ�һ�ڵ�����ݣ�ָ�����ݵ�ָ�룩
//����ERROR��ʾδ�ҵ�����ERROR��Ϊָ�����ݵ�ָ��
void* GetNextData_LinkedList(LinkedListNode*);
//��ȡ����������ָ���ڵ�ĺ�һ�ڵ��ָ�루ָ�����ݵ�ָ�룩
//����ERROR��ʾδ�ҵ�����ERROR��Ϊ�ڵ�ָ��
LinkedListNode* GetNextPtr_LinkedList(LinkedListNode*);
//��ȡ����������ָ���ڵ��ǰһ�ڵ�����ݣ�ָ��������ͷ�ڵ��ָ��,ָ�����ݵ�ָ�룩
//����ERROR��ʾδ�ҵ�����ERROR��Ϊָ�����ݵ�ָ��
void* GetPrioData_LinkedList(LinkedList, LinkedListNode*);
//��ȡ����������ָ���ڵ��ǰһ�ڵ��ָ�루ָ��������ͷ�ڵ��ָ��,ָ�����ݵ�ָ�룩
//����ERROR��ʾδ�ҵ�����ERROR��Ϊ�ڵ�ָ��
LinkedListNode* GetPrioPtr_LinkedList(LinkedList, LinkedListNode*);
//����ָ��ĳ�ڵ��ָ���ȡ����������ָ���ڵ��λ����ţ�ָ��������ͷ�ڵ��ָ��,ָ�����ݵ�ָ�룩
//����ERROR��ʾδ�ҵ�����ERROR��Ϊλ�����
long PtrToPos(LinkedList, LinkedListNode*);
//���ݵ���������ָ���ڵ��λ����Ż�ȡָ��ĳ�ڵ��ָ�루ָ��������ͷ�ڵ��ָ��,λ����ţ�
//����ERROR��ʾδ�ҵ�����ERROR��Ϊ�ڵ�ָ��
LinkedListNode* PosToPtr(LinkedList, long);
//�ڸ����ڵ�֮ǰ�������ݣ��ڵ�ָ��,ָ����������ݵ�ָ��,����˵��(�ο���DATATYPE_*)��
//����ERROR��ʾ����ʧ�ܣ���ERROR��Ϊ����Ľڵ�ָ��
LinkedListNode* InsertBefore_LinkedList(LinkedListNode*, void*, int);
//�ڸ����ڵ�֮��������ݣ��ڵ�ָ��,ָ����������ݵ�ָ��,����˵��(�ο���DATATYPE_*)��
//����ERROR��ʾ����ʧ�ܣ���ERROR��Ϊ����Ľڵ�ָ��
LinkedListNode* InsertAfter_LinkedList(LinkedListNode*, void*, int);
//ɾ��ָ���ڵ㣨ָ��������ͷ�ڵ��ָ��,�ڵ�ָ�룩
int Delete_LinkedList(LinkedList, LinkedListNode*);