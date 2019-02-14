/*
	顺序表
*/
#pragma once
#include "Structs.h"

//初始化顺序表（指向顺序表的指针,类型说明(参考宏DATATYPE_*)）
//初始size上限20
int Init_SqList(SqList*, int);
//释放顺序表（指向顺序表的指针）
int Free_SqList(SqList*);
//清空顺序表的数据区（指向顺序表的指针）
int Clear_SqList(SqList*);
//判断顺序表是否为空（指向顺序表的指针）
int IsEmpty_SqList(SqList*);
//获取顺序表的数据区有效长度（指向顺序表的指针）
long GetLength_SqList(SqList*);
//获取顺序表指定位置的数据（指向顺序表的指针,数据区的指定位置）
//返回ERROR表示未找到，非ERROR则为指向数据的指针
void* GetData_SqList(SqList*, long);
//获取指定数据在顺序表中的位置（指向顺序表的指针,指向数据的指针）
//返回ERROR表示未找到，非ERROR则为数据位置
long FindDataPos_SqList(SqList*, void*);
//获取数据区中指定位置之后一位的数据（指向顺序表的指针,数据区的指定位置）
//返回ERROR表示未找到，非ERROR则为指向数据的指针
void* GetNextData_SqList(SqList*, long);
//获取数据区中指定位置之前一位的数据（指向顺序表的指针,数据区的指定位置）
//返回ERROR表示未找到，非ERROR则为指向数据的指针
void* GetPrioData_SqList(SqList*, long);
//在给定位置之前插入数据（指向顺序表的指针,数据区的指定位置,指向待插入数据的指针）
//返回ERROR表示插入失败，非ERROR则为插入的位置
long InsertData_SqList(SqList*, long, void*);
//删除给定位置的数据（指向顺序表的指针,数据区的指定位置）
int DeleteData_SqList(SqList*, long);