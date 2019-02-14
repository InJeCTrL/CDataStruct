/*
	栈（链式栈）
*/
#pragma once
#include "Structs.h"
#include "LinkedList.h"

//初始化链式栈（指向栈结构的指针）
int Init_Stack(Stack*);
//清空链式栈,栈仍可使用（指向栈结构的指针）
int Clear_Stack(Stack*);
//判断链式栈是否为空（指向栈结构的指针）
int IsEmpty_Stack(Stack*);
//获取队列的长度（指向栈结构的指针）
long GetLength_Stack(Stack*);
//向链栈压栈（指向栈结构的指针,指向数据的指针,类型说明(参考宏DATATYPE_*)）
//返回ERROR表示入栈失败（分配失败），非ERROR则为成功入栈
int Push_Stack(Stack*, void*, int);
//链栈出栈（指向栈结构的指针）
//返回ERROR表示出栈失败（栈已空），非ERROR则为成功出栈
int Pop_Stack(Stack*);
//获取链式栈栈顶数据指针（指向栈结构的指针）
//返回ERROR表示栈已空，非ERROR则为栈顶数据指针
void* GetTopData_Stack(Stack*);
//获取链式栈栈顶数据的数据类型（指向栈结构的指针）
//返回ERROR表示栈已空，非ERROR则为栈顶数据类型
int GetTopDataType_Stack(Stack*);