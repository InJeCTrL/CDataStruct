#pragma once
#include <malloc.h>
#include <string.h>

#define NO_ERROR			0	//正常调用返回
#define ERROR				-1	//出现错误

#define DATATYPE_INT		0	//整型数据类型
#define DATATYPE_LONG		1	//长整型数据类型
#define DATATYPE_FLOAT		2	//单精度浮点型数据类型
#define DATATYPE_DOUBLE		3	//双精度浮点数据类型
#define DATATYPE_CHAR		4	//字符型数据类型
#define DATATYPE_CSTRING	5	//C字符串型数据类型

//顺序表
typedef struct
{
	void *DataList;//数据区域
	long length;//当前顺序表长度
	long size;//顺序表总长度
	int DataType;//数据类型
}SqList;

//单向链表
typedef struct LinkedListNode
{
	void *Data_ptr;//数据域指针
	struct LinkedListNode *next;//后继指针域
	int DataType;//数据类型,每个节点的数据类型可以不一样
}LinkedListNode, *LinkedList;

//双向链表
typedef struct DLinkedListNode
{
	void *Data_ptr;//数据域指针
	struct DLinkedListNode *prev, *next;//前驱、后继指针域
	int DataType;//数据类型,每个节点的数据类型可以不一样
}DLinkedListNode, *DLinkedList;

//链式栈
typedef struct
{
	LinkedListNode StackData;//栈数据域的头节点（单向链表）
	LinkedListNode *StackTop;//指向栈顶的指针
	long Length;//当前栈的容量
}Stack;

//链式队列
typedef struct
{
	LinkedListNode QueueData;//队列数据域的头节点（单向链表）
	LinkedListNode *QueueHead, *QueueTail;//指向队列头、尾的指针
	long Length;//当前队列的容量
}Queue;