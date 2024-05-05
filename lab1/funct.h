
int cmp(const void *a,const void *b) {
	return *(int*)a-*(int*)b;
}
status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(L.elem!=NULL)
		return INFEASIBLE;
	L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
	/********** End **********/
}
status DestroyList(SqList& L)
// 如果线性表L存在，判空线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	free(L.elem);
	L.elem = NULL;
	return OK;
	/********** End **********/
}
status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
  	L.length = 0;
	return OK;
	/********** End **********/
}
status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	else if(L.length==0)
		return TRUE;
	else 
		return FALSE;
	/********** End **********/
}
status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	return L.length;

	/********** End **********/
}
status GetElem(SqList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	if(i>L.length||i<=0)
		return ERROR;
	e=L.elem[i-1];
	return OK;
	/********** End **********/
}
status LocateElem(SqList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	for (int i = 0; i<L.length; i++)
	{
		if(L.elem[i]==e)
		{
			e = i+1;
			return i+1;
		}
	}
	return 0;

	/********** End **********/
}
status PriorElem(SqList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	if(L.elem[0]==e)
		return ERROR;
	for (int i = 1; i < L.length;i++)
	{
		if(e==L.elem[i])
		{
			pre = L.elem[i - 1];
			return OK;
		}
	}
	return ERROR;
	/********** End **********/
}
status NextElem(SqList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	for (int i = 0; i <=L.length-2;i++)
	{
		if(e==L.elem[i])
		{
			next = L.elem[i+1];
			return OK;
		}
	}
	return ERROR;
}
status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	else if(i<=0||i>L.length+1)
		return ERROR;
	else if(L.length==L.listsize)
	{
		ElemType *newbase;
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if(newbase==NULL)
			return OVERFLOW;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	for (int j = L.length - 1; j >= i - 1;j--) // 往后移动
		L.elem[j + 1] = L.elem[j];
	L.elem[i-1] = e;//插入
	L.length++;
	return OK;
	/********** End **********/
}
status ListDelete(SqList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	if(i<=0||i>L.length)
		return ERROR;
	else if(i==L.length)
		e=L.elem[i-1];
	else 
	{
        e=L.elem[i-1];
		for (int a = 0; a< L.length-i+1;a++)
		{
			L.elem[i -1+a]=L.elem[i + a] ;
		}
	}
	L.length--;
	return OK;
    /********** End **********/
}
status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;
	printf("\n-----------all elements -----------------------\n");
	for (int i = 0; i < L.length;i++)
		printf("%d ", L.elem[i]);
	printf("\n------------------ end ------------------------\n");
	return OK;
	/********** End **********/
}
status SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(L.elem==NULL)
		return INFEASIBLE;	
 	FILE *fp=fopen(FileName,"w");
	if(fp==NULL)
		printf("文件打开失败");
	else 
		printf("成功打开文件");
	for (int i =0; i < L.length;i++)
		fprintf(fp,"%d ",L.elem[i]);
	fclose(fp);
	return OK;
	/********** End **********/
}
status LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	if(strcmp(FileName,"D:/HUST-DataStructure-Labs/lab1/data/1.dat")!=0 && 
		strcmp(FileName,"D:/HUST-DataStructure-Labs/lab1/data/2.dat")!=0)
		return ERROR;
	if(L.elem!=NULL)
		return INFEASIBLE;
	L.listsize = LIST_INIT_SIZE;
	L.length = 0;
	L.elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	FILE *fp=fopen(FileName,"r");
	int a, i = 0;
	while(fscanf(fp,"%d ",&a)==1)
	{
		L.elem[i++]=a;
		L.length++;
	}
	fclose(fp);
	return OK;
	/********** End **********/
}
status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	Lists.elem[Lists.length].L.elem = NULL;
	InitList(Lists.elem[Lists.length].L);
	strcpy(Lists.elem[Lists.length].name,ListName);
	Lists.length++;
	return 0;
	/********** End **********/
}
status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
     for (int i = 0; i < Lists.length;i++)
    {
        if(strcmp(ListName,Lists.elem[i].name)==0)
        {
            
            for(int t=i;t<Lists.length-1;t++)
            {
               Lists.elem[t]=Lists.elem[t+1];
               strcpy(Lists.elem[t].name, Lists.elem[t+1].name);
            }
            Lists.length--;
            return OK;
        }
    }
	return INFEASIBLE;
}
int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
	for (int i = 0; i < Lists.length;i++)
	{
		if(strcmp(ListName,Lists.elem[i].name)==0)
			return i+1;
	}
	return 0;
	/********** End **********/
}
status MaxSubArray(SqList L)
{
	if(L.length==0)
		return INFEASIBLE;
    int res=-999999,sum=0;
    for(int i=0;i<L.length;i++)
	{
        if(sum<0){
            sum=L.elem[i];
        }else{
            sum+=L.elem[i];
        }
        res=res>sum?res:sum;
    }
    return res;
}
status SubArrayNum(SqList L,int K)
{
	if(L.elem==NULL)
		return INFEASIBLE;
	else if(L.length==0)
		return ERROR;
	else 
	{
		int sum = 0, count = 0;
		for (int i = 0; i < L.length;i++)
		{
			for (int j = i; j < L.length;j++)
			{
				sum += L.elem[i];
				if(sum==K)
					count++;
			}
		}
		return count;
	}
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
        printf("    	  13. MaxSubArray   14.SubArrayNum\n");
        printf("    	  15. SortList      16.Save_in_file\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
		printf("线性表：");
		for (int i = 0; i < 10;i++)
		{
			if(lists.elem[i].L.elem!=NULL)
				printf("%d ", i);
		}
		printf("已初始化\n");
		printf("请选择你的操作[0~16]:"); 
}
