/*
	队列（链式队列）
*/
#pragma once
#include "Structs.h"
#include "LinkedList.h"

//初始化链式队列（指向队列结构的指针）
int Init_Queue(Queue*);
//清空链式队列,队列仍可使用（指向队列结构的指针）
int Clear_Queue(Queue*);
//判断链式队列是否为空（指向队列结构的指针）
int IsEmpty_Queue(Queue*);
//获取队列的长度（指向队列结构的指针）
long GetLength_Queue(Queue*);
//向链队列队尾压入数据（指向队列结构的指针,指向数据的指针,类型说明(参考宏DATATYPE_*)）
//返回ERROR表示入队失败（分配失败），非ERROR则为成功入队
int Push_Queue(Queue*, void*, int);
//链队列队头出队（指向队列结构的指针）
//返回ERROR表示出队失败（队列已空），非ERROR则为成功出队
int Pull_Queue(Queue*);
//获取链式队列队头数据指针（指向队列结构的指针）
//返回ERROR表示队列已空，非ERROR则为队列头数据指针
void* GetHeadData_Queue(Queue*);
//获取链式队列队头数据的数据类型（指向队列结构的指针）
//返回ERROR表示队列已空，非ERROR则为队头数据类型
int GetHeadDataType_Queue(Queue*);