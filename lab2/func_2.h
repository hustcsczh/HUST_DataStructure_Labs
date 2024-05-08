#include"def_2.h"
status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L!=NULL)
        return INFEASIBLE;
    L=(LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return OK;
    /********** End **********/
}
status DestroyList(LinkList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    LNode *p;
	for (int i = 0; i < lists.length;i++)
	{
		if(lists.elem[i].L==L)
			*lists.elem[i].name ='\0';
	}
	while (L)
	{
		p = L;
		L = L->next;
		free0(p);
	}
	lists.length--;
	return OK;
    /********** End **********/
}
status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    LNode *p;
    while(L->next)
    {
        p = L->next;
        L->next = p -> next;
        free0(p);
    }
    return OK;
    /********** End **********/
}
status ListEmpty(LinkList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    else if(L->next)
        return FALSE;
    else
        return TRUE;

    /********** End **********/
}
int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    LNode *p;
    p = L->next;
    int count = 0;
    while(p)
    {
        p = p->next;
        count++;
    }
    return count;
    /********** End **********/
}
status GetElem(LinkList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    int length = ListLength(L);
    if(i<=0||i>length)
        return ERROR;
    LNode *p;
    p = L->next;
    while(--i)
        p = p->next;
    e = p->data;
    return OK;
    /********** End **********/
}
status LocateElem(LinkList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    LNode *p;
    p = L->next;
    int count = 1;
    while(p)
    {
        if(e==p->data)
            return count;
		p = p->next;
		count++;
    }
    return ERROR;
    /********** End **********/
}
status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    if(L->data==e) //首位
        return ERROR;
    LNode *p;
    p = L;
    while(p->next)
    {
        if(p->next->data==e&&p!=L)
        {
            pre = p->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
    /********** End **********/
}
status NextElem(LinkList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
     if(L==NULL)
        return INFEASIBLE;
    LNode *p;
    p = L;
    while(p->next)
    {
        if(p->data==e)
        {
            next = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
    /********** End **********/
}
status ListInsert(LinkList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    else if(i>1+ListLength(L)||i<=0)
        return ERROR;
    else if(i==1+ListLength(L))
    {
        LNode *p;
        p = L;
        while(p->next)
            p=p->next;
        LinkList L1;
        L1=(LinkList) malloc(sizeof(LNode));
        L1->data = e;
        L1->next = p->next;
        p->next = L1;
        return OK;
    }
    else
    {
        LNode *p;
        p = L;
        while(--i)
            p = p->next;
        LinkList L1;
        L1=(LinkList) malloc(sizeof(LNode));
        L1->data = e;
        L1->next = p->next;
        p->next = L1;
        return OK;
    }
}
status ListDelete(LinkList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    else if(i<=0||i>ListLength(L))
        return ERROR;
    else
    {
        LNode *p;
        p = L;
        while(--i)
            p = p->next;
        e = p->next->data;
        LinkList p2=(LinkList) malloc(sizeof(LNode));
        p2 = p->next;
        p->next = p->next->next;
        free(p2);
    }
    return OK;
    /********** End **********/
}
status ListTraverse(LinkList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L==NULL)
        return INFEASIBLE;
    LNode *p;
    p = L->next;
	printf("\n-----------all elements -----------------------\n");
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
	printf("\n------------------ end ------------------------\n");
    return OK;

    /********** End **********/
}
status SaveList(LinkList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    if(L==NULL)
        return INFEASIBLE;
    FILE *fp=fopen(FileName,"w");
    LNode *p;
    p = L->next;
	while(p)
    {
		fprintf(fp,"%d ",p->data);
        p = p->next;
    }
	fclose(fp);
    return OK;
    /********** End 1 **********/
}
status LoadList(char FileName[],char name[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
	if(strcmp(FileName,"D:/data/1.dat")!=0 && strcmp(FileName,"D:/data/2.dat")!=0)
		return ERROR;
    lists.elem[lists.length].L = (LinkList)malloc(sizeof(LNode));
	strcpy(lists.elem[lists.length].name, name);
	FILE *fp=fopen(FileName,"r");
    int a;
    LinkList L1, p;
    p = lists.elem[lists.length].L;
    while(fscanf(fp,"%d ",&a)==1)
	{
		L1=(LinkList) malloc(sizeof(LNode));
        p->next = L1;
        L1->data = a;
        L1->next = NULL;
        p=L1;
	}
    fclose(fp);
    return OK;
    /********** End 2 **********/
}
status reverseList(LinkList &L)
{
	// Lp Aq  Bm
	if(L->next==NULL)
		return ERROR;
	LNode *p, *q, *m;
	p = L;
	q = p->next;
	L->next = NULL;
	if(q!=NULL)
	{
		m = q->next;
		p = NULL;
		while(m)
		{
			q->next = p;
			p = q;
			q = m;
			m = q->next;
		}
		L->next = q;
		q->next = p;
	}
	else
		L->next = p;
	return OK;
}
status RemoveNthFromEnd(LinkList &L,int n)
{
	int i = ListLength(L)- n+1;
	if(i<=0||i>ListLength(L))
        return ERROR;
    else
    {
        LNode *p;
        p = L;
        while(--i)
            p = p->next;
        LinkList p2=(LinkList) malloc(sizeof(LNode));
        p2 = p->next;
        p->next = p->next->next;
        free(p2);
    }
    return OK;
}
status sortList(LinkList &L)
{
	if(L->next==NULL)
		return ERROR;
	LNode *p, *q;// 1 -2 -8 0
	for (p = L->next; p->next;p=p->next)
	{
		for (q = p->next; q;q=q->next)
		{
			if(p->data>q->data)
			{
				p->data = p->data + q->data;
				q->data = p->data - q->data;
				p->data = p->data - q->data;
			}
		}
	}
	return OK;
}
status check(char name[])
{
	for (int i = 0; i < lists.length;i++)
	{
		if(strcmp(name,lists.elem[i].name)==0)
			return i;
	}
	return -1;
}
status addlist(char name[])
{
	lists.elem[lists.length].L=(LinkList)malloc(sizeof(LNode));
    lists.elem[lists.length].L->next = NULL;
	strcpy(lists.elem[lists.length].name,name);
	lists.length++;
	return 0;
}
void My_print(void)
{
       system("cls");
	    printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1.  InitList      7.  LocateElem\n");
	  	printf("    	  2.  DestroyList   8.  PriorElem\n");
	  	printf("    	  3.  ClearList     9.  NextElem\n");
        printf("    	  4.  ListEmpty     10. ListInsert\n");
        printf("    	  5.  ListLength    11. ListDelete\n");
        printf("    	  6.  GetElem       12. ListTraverse\n");
		printf("-------------------------------------------------\n");
        printf("    	  13. reverseList   14.RemoveNthFromEnd\n");
        printf("    	  15. SortList      16.Save_in_file\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
		printf("%d个线性表已初始化\n",lists.length);
		for (int i = 0; i < lists.length;i++)
		{
			if(lists.elem[i].L!=NULL)
				printf("%s ", lists.elem[i].name);
		}
		printf("请选择你的操作[0~16]:"); 
}