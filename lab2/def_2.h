#include "stdio.h"
#include "stdlib.h"
#include "stdlib.h"
#include "string.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct LNode{  //单链表（链式结构）结点的定义
      ElemType data;
      struct LNode *next;
    }LNode,*LinkList;

typedef struct{  //单链表的管理表定义
     struct { 
		char name[30];
     	LinkList L;	
      } elem[10];
      int length;
      int listsize;
}LinkLists;
LinkLists lists;

struct ptr{
    void *pused[100],*pfree[100];
    int len_used,len_free;
    } pm;
void free0(void *p)
{
    pm.pfree[pm.len_free++]=p;
    memset(p,0,sizeof(LNode));
    free(p);
}

status InitList(LinkList &L);
status DestroyList(LinkList &L);
status ClearList(LinkList &L);
status ListEmpty(LinkList L);
int ListLength(LinkList L);
status GetElem(LinkList L, int i, ElemType &e);
status LocateElem(LinkList L, ElemType e);
status PriorElem(LinkList L, ElemType e, ElemType &pre);
status NextElem(LinkList L, ElemType e, ElemType &next);
status ListInsert(LinkList &L, int i, ElemType e);
status ListDelete(LinkList &L, int i, ElemType &e);
status ListTraverse(LinkList L);
status SaveList(LinkList L, char FileName[]);
status LoadList(char FileName[], char name[]);
status reverseList(LinkList &L);
status RemoveNthFromEnd(LinkList &L, int n);
status sortList(LinkList &L);
status check(char name[]);
status addlist(char name[]);
void My_print(void);