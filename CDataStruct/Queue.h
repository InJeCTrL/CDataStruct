/*
	���У���ʽ���У�
*/
#pragma once
#include "Structs.h"
#include "LinkedList.h"

//��ʼ����ʽ���У�ָ����нṹ��ָ�룩
int Init_Queue(Queue*);
//�����ʽ����,�����Կ�ʹ�ã�ָ����нṹ��ָ�룩
int Clear_Queue(Queue*);
//�ж���ʽ�����Ƿ�Ϊ�գ�ָ����нṹ��ָ�룩
int IsEmpty_Queue(Queue*);
//��ȡ���еĳ��ȣ�ָ����нṹ��ָ�룩
long GetLength_Queue(Queue*);
//�������ж�βѹ�����ݣ�ָ����нṹ��ָ��,ָ�����ݵ�ָ��,����˵��(�ο���DATATYPE_*)��
//����ERROR��ʾ���ʧ�ܣ�����ʧ�ܣ�����ERROR��Ϊ�ɹ����
int Push_Queue(Queue*, void*, int);
//�����ж�ͷ���ӣ�ָ����нṹ��ָ�룩
//����ERROR��ʾ����ʧ�ܣ������ѿգ�����ERROR��Ϊ�ɹ�����
int Pull_Queue(Queue*);
//��ȡ��ʽ���ж�ͷ����ָ�루ָ����нṹ��ָ�룩
//����ERROR��ʾ�����ѿգ���ERROR��Ϊ����ͷ����ָ��
void* GetHeadData_Queue(Queue*);
//��ȡ��ʽ���ж�ͷ���ݵ��������ͣ�ָ����нṹ��ָ�룩
//����ERROR��ʾ�����ѿգ���ERROR��Ϊ��ͷ��������
int GetHeadDataType_Queue(Queue*);