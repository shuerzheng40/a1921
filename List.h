#ifndef List_h
#define List_h
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define n 11
#define m 3 

typedef int dataType;
typedef struct node{
	dataType data;
	struct node *next;
}LinkList;

LinkList* CreateList1();    //创建一个单链表
LinkList* CreateList2();
void Yuesefu(LinkList *L);
int Size(LinkList *L);
void Insert(LinkList *L, int k, dataType x);
void Delete(LinkList *L, int k);
int Empty(LinkList *L);
dataType GetData(LinkList *L, int k);
LinkList* Find(LinkList *L,dataType x);
void Print(LinkList *L);
void ClearList(LinkList *L);



#endif
