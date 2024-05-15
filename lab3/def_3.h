#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXLENGTH 100
#define LISTINCREMENT 10
#define N 10
typedef int status;
typedef int KeyType; 
typedef struct {
    KeyType  key;
    char others[20];
} TElemType;                     //二叉树结点类型定义
typedef struct BiTNode{  
	TElemType  data;            
	struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;     //二叉链表结点的定义
typedef struct {
    struct 
    {
        char name[30];
        BiTree T;
    } elem[10];
    int length;
    int listsize;
} BiTreelists;       ////二叉树的管理表定义
BiTreelists lists;
typedef struct {
    int pos;
    TElemType data;
} DEF;
typedef struct QUEUE
{
    BiTree elem[MAXLENGTH];
    int front,length;
} QUEUE;
void iniQueue(QUEUE &Q);
status enQueue(QUEUE &Q, BiTree e);
status deQueue(QUEUE &Q, BiTree &e);
typedef struct STACK
{
    BiTree elem[N];
    int top1;
} STACK;
void inistack(STACK &S);
status push(STACK &S, BiTree e);
BiTree pop(STACK &S);

#define free free0
#undef free
int freed=FALSE;
KeyType e;
void visit(BiTree T);
void free0(void *p);
status CreateBiTree(BiTree &T, DEF definition[]);
status DestroyBiTree(BiTree &T);
status ClearBiTree(BiTree &T);
status BiTreeEmpty(BiTree T);
status BiTreeDepth(BiTree T);
BiTNode *LocateNode(BiTree T, KeyType e);
status Assign(BiTree &T, KeyType e, TElemType value); /********** End **********/
BiTNode *GetSibling(BiTree T, KeyType e);             // 获得兄弟节点
BiTNode *Get(BiTree T, KeyType e);                    // 获得双亲节点
BiTNode *Getright(BiTree p);                          // 获得左子树最右节
status InsertNode(BiTree &T, KeyType e, int LR, TElemType c);
status DeleteNode(BiTree &T, KeyType e);
status PreOrderTraverse(BiTree T, void (*visit)(BiTree));   // 前序遍历
status InOrderTraverse(BiTree T, void (*visit)(BiTree));    // 中序遍历
status PostOrderTraverse(BiTree T, void (*visit)(BiTree));  // 后序遍历
status LevelOrderTraverse(BiTree T, void (*visit)(BiTree)); // 层序遍历
status MaxPathSum(BiTree T);
BiTNode *LowestCommonAncestor(BiTree T, KeyType e1, KeyType e2);
BiTNode *InvertTree(BiTree &T);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
status SaveBiTree(BiTree T, char FileName[]);
status LoadBiTree(BiTree &T, char FileName[]);
status check(char name[]);
void My_print(void);