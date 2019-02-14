/*
	链表（单向、双向）
*/
#pragma once
#include "Structs.h"

//初始化单向链表（指向单向链表头节点的指针）
int Init_LinkedList(LinkedList);
//清空单向链表,只留下头节点（指向单向链表头节点的指针）
int Clear_LinkedList(LinkedList);
//判断单向链表是否为空（指向单向链表头节点的指针）
int IsEmpty_LinkedList(LinkedList);
//获取单向链表的长度（指向单向链表头节点的指针）
long GetLength_LinkedList(LinkedList);
//根据位置序号获取单向链表指定位置的数据（指向单向链表头节点的指针,位置序号）
//返回ERROR表示未找到，非ERROR则为指向数据的指针
void* GetDataByPos_LinkedList(LinkedList, long);
//根据节点指针获取单向链表指定位置的数据（指向单向链表某节点的指针）
void* GetDataByPtr_LinkedList(LinkedListNode*);
//获取指定数据在单向链表中的位置（指向单向链表头节点的指针,指向数据的指针,待查找类型说明(参考宏DATATYPE_*)）
//返回ERROR表示未找到，非ERROR则为位置序号
long FindPosByData_LinkedList(LinkedList, void*, int);
//获取指向指定数据节点的指针（指向单向链表头节点的指针,指向数据的指针,待查找类型说明(参考宏DATATYPE_*)）
//返回ERROR表示未找到，非ERROR则为节点指针
LinkedListNode* FindPtrByData_LinkedList(LinkedList, void*, int);
//获取单向链表中指定节点的后一节点的数据（指向数据的指针）
//返回ERROR表示未找到，非ERROR则为指向数据的指针
void* GetNextData_LinkedList(LinkedListNode*);
//获取单向链表中指定节点的后一节点的指针（指向数据的指针）
//返回ERROR表示未找到，非ERROR则为节点指针
LinkedListNode* GetNextPtr_LinkedList(LinkedListNode*);
//获取单向链表中指定节点的前一节点的数据（指向单向链表头节点的指针,指向数据的指针）
//返回ERROR表示未找到，非ERROR则为指向数据的指针
void* GetPrioData_LinkedList(LinkedList, LinkedListNode*);
//获取单向链表中指定节点的前一节点的指针（指向单向链表头节点的指针,指向数据的指针）
//返回ERROR表示未找到，非ERROR则为节点指针
LinkedListNode* GetPrioPtr_LinkedList(LinkedList, LinkedListNode*);
//根据指向某节点的指针获取单向链表中指定节点的位置序号（指向单向链表头节点的指针,指向数据的指针）
//返回ERROR表示未找到，非ERROR则为位置序号
long PtrToPos(LinkedList, LinkedListNode*);
//根据单向链表中指定节点的位置序号获取指向某节点的指针（指向单向链表头节点的指针,位置序号）
//返回ERROR表示未找到，非ERROR则为节点指针
LinkedListNode* PosToPtr(LinkedList, long);
//在给定节点之前插入数据（节点指针,指向待插入数据的指针,类型说明(参考宏DATATYPE_*)）
//返回ERROR表示插入失败，非ERROR则为插入的节点指针
LinkedListNode* InsertBefore_LinkedList(LinkedListNode*, void*, int);
//在给定节点之后插入数据（节点指针,指向待插入数据的指针,类型说明(参考宏DATATYPE_*)）
//返回ERROR表示插入失败，非ERROR则为插入的节点指针
LinkedListNode* InsertAfter_LinkedList(LinkedListNode*, void*, int);
//删除指定节点（指向单向链表头节点的指针,节点指针）
int Delete_LinkedList(LinkedList, LinkedListNode*);