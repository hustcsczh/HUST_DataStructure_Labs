#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int status;
typedef int ElemType; //数据元素类型定义
typedef struct{  //顺序表（顺序结构）的定义
	      int * elem;
	      int length;
	      int listsize;
}SqList;
typedef struct{  //线性表的管理表定义
     struct { 
		char name[30];
     	SqList L;	
      } elem[10];
      int length;
      int listsize;
}LISTS;
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
	if(strcmp(FileName,"D:/data/1.dat")!=0 && strcmp(FileName,"D:/data/2.dat")!=0)
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



int main(void)
{
	LISTS lists;
	lists.length = 0;
	lists.listsize = 10;
	for (int i = 0; i < 10;i++)
		lists.elem[i].L.elem = NULL;
	SqList L;  int op=1;
	int count = 0;
	while(op)
	{
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
	   	scanf("%d",&op);
		getchar();
		switch(op)
	   	{
		case 0:
			break;
		case 1:
			{
				printf("请输入线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int result=InitList(lists.elem[id].L);
				if (result ==INFEASIBLE)
					printf("线性表 %d 已存在！\n",id);
				else
					printf("线性表 %d 创建成功!\n",id);
	            printf("点击Enter进行下一步");getchar();
				break;
			}
		case 2:
			{
				printf("请输入要销毁的线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int result=DestroyList(lists.elem[id].L);
		   		if(result==OK)
		            printf("线性表 %d 销毁成功！\n",id);
		   		else 
					printf("线性表 %d 不存在！\n",id);
	   			printf("点击Enter进行下一步");
				getchar();
				break;
			}
		case 3:
			{
				printf("请输入线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int result=ClearList(lists.elem[id].L);
		   		if(result==OK)
			   printf("线性表 %d 清空成功！\n",id);
		   		else printf("线性表 %d 不存在！\n",id);
	            printf("点击Enter进行下一步");
				getchar();
			 
			break;
			}
		case 4:
		   	{
				printf("请输入线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int result=ListEmpty(lists.elem[id].L);
				if(result==TRUE)
			   		printf("线性表 %d 是空的！\n",id);
		   		else 
					printf("线性表 %d 非空！\n",id);
	   			printf("点击Enter进行下一步");
				getchar();
				break;
			}
		case 5:
			{
				printf("请输入线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int result=ListLength(lists.elem[id].L);
		   	if(result==INFEASIBLE)
			   	printf("线性表 %d 不存在！\n",id);
		   	else printf("线性表 %d 长度为 %d\n",id,result);
	            printf("点击Enter进行下一步");
				getchar();
			break;
			}
		case 6:
		   	{
				printf("请输入线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int i = 0,e;
	        	printf("输入你想获取的第i个元素: ");
		   		scanf("%d", &i);
				int result=GetElem(lists.elem[id].L,i,e);
		   		if (result!=OK)
			   	printf("获取失败\n");
		   		else 
				printf("第 %d 个元素是 %d\n", i, e);
	        	printf("点击Enter进行下一步");
				getchar();
				getchar();
				break;
		   	}
		case 7:
		  	{
				printf("请输入线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			printf("输入你想查找的元素e的大小: ");
			int e1;
			scanf("%d", &e1);
			int result = LocateElem(lists.elem[id].L, e1);
			if(result==0)
				printf("表中不存在元素%d\n", e1);
		   else if(result==INFEASIBLE)
			   printf("线性表 %d 不存在\n",id);
		   else
			   printf("%d 的序号是: %d\n", e1, result);
			printf("点击Enter进行下一步");
			getchar();
			getchar();
			break;
		  	}
		case 8:
		  	{
				printf("请输入线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			printf("输入你想查找的元素e的前驱: ");
			int e2=0, pre=0;
			scanf("%d", &e2);
			int result =PriorElem(lists.elem[id].L,e2,pre);
			if(result==ERROR)
				printf("%d的前驱不存在\n",e2);
		   	else if(result==INFEASIBLE)
			   printf("线性表 %d 不存在",id);
		   	else
			   printf("%d 的前驱是: %d\n", e2, pre);
			printf("点击Enter进行下一步");
			getchar();
			getchar();
			break;
		 	}
		case 9:
		  	{
				printf("请输入线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
	        printf("输入你想查找的元素e的后继: ");
			int e=0,next=0;
			scanf("%d", &e);
			int result =NextElem(lists.elem[id].L,e,next);
			if(result==ERROR)
				printf("%d的后继不存在\n",e);
		   	else if(result==INFEASIBLE)
			   printf("线性表 %d 不存在\n",id);
		   	else
			   printf("%d 的后继是: %d\n", e, next);
			printf("点击Enter进行下一步");
			getchar();
			getchar();
			break;
		  	}
		case 10:
		  	{
				printf("请输入线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			printf("输入你想插入的元素e和位置i:  ");
			int i, e;
			scanf("%d %d", &e, &i);
			int result = ListInsert(lists.elem[id].L, i, e);
			if(result==INFEASIBLE)
			   printf("线性表 %d 不存在\n",id);
		   	else if(result==ERROR)
			   printf("插入位置错误\n");
		   	else
			   printf("插入操作成功\n");
			printf("点击Enter进行下一步");
			getchar();
			getchar();
			break;
		  	}
		case 11:
		  	{
				printf("请输入线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			printf("输入你想删除的元素的位置i:  ");
			int i, e;
			scanf("%d",&i);
			int result = ListDelete(lists.elem[id].L, i, e);
			if (result == INFEASIBLE)
				 printf("线性表 %d 不存在\n",id);
			else if (result == ERROR)
				 printf("删除位置错误\n");
			else
				 printf("删除操作成功，删除的元素是 %d\n",e);
			printf("点击Enter进行下一步");
			getchar();
			getchar();
			break;
			}
		case 12:
		  	{
			printf("请输入线性表的id(0-9): ");
			int id;
			scanf("%d", &id);
			getchar();
		   	int result=ListTraverse(lists.elem[id].L);
			if(result==INFEASIBLE)
			   printf("线性表 %d 是空表！\n",id);
			printf("点击Enter进行下一步");
			getchar();
			break;
		  	}
		case 13:
		{
			printf("请输入线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			int result=MaxSubArray(lists.elem[id].L);
			if(result==INFEASIBLE)
			   printf("线性表 %d 是空表！\n",id);
			else
				printf("连续子数组的最大和为：%d\n", result);
			printf("点击Enter进行下一步");
			getchar();
			break;
		}
	   	case 14:
		{
			printf("请输入线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			int K;
			printf("请输入数组和 K 的值：");
			scanf("%d", &K);
			getchar();
			int result=SubArrayNum(lists.elem[id].L,K);
			if(result==ERROR)
			   printf("线性表是空表！\n");
			else if(result==INFEASIBLE)
				printf("线性表不存在");
			else
				printf("和为 %d 的子数组有 %d 个\n", K, result);
			printf("点击Enter进行下一步");
			getchar();
			break;
		}
		case 15:
		{
			printf("请输入线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
			if(lists.elem[id].L.length==0)
			   	printf("线性表是空表！\n");
			else if(lists.elem[id].L.elem==NULL)
				printf("线性表不存在");
			else
			{
				qsort(lists.elem[id].L.elem,lists.elem[id].L.length,sizeof(ElemType),cmp);
				printf("已成功由小到大排序\n");
				ListTraverse(lists.elem[id].L);
			}
			printf("点击Enter进行下一步");
			getchar();
			break;
		}
		case 16:
		{
			int opp;
			do
			{
			printf("请选择操作输入 0.退出系统  1. 表示将线性表存入文件， 2. 表示将文件读入线性表：");
			scanf("%d", &opp);
			getchar();
			FILE *fp;char filename[30];int i;
			if(opp==1)
			{
				printf("请输入一个线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				strcpy(filename, "D:/data/3.dat");
				int result = SaveList(lists.elem[id].L, filename);
				if(lists.elem[id].L.elem==NULL)
					printf("线性表未初始化\n");
				else if(result==INFEASIBLE)
					printf("线性表为空\n");
				else
					printf("成功存入路径为 D:/data/3.dat 的文件中\n");
				printf("点击Enter进行下一步");
				getchar();
			}
			else if(opp==2)
			{
				printf("可选的文件地址： D:/data/1.dat   or  D:/data/2.dat\n");
				printf("input file name: ");
				gets(filename);
				printf("请输入一个未初始化的线性表的id(0-9): ");
				int id;
				scanf("%d", &id);
				getchar();
				int result=LoadList(lists.elem[id].L, filename);
				if(result==INFEASIBLE)
					printf("线性表 %d 已初始化\n",id);
				else if(result==ERROR)
					printf("文件地址错误\n");
				else
					printf("已将文件内容读入线性表 %d 中\n",id);
				printf("点击Enter进行下一步");
				getchar();
			}
			else
				printf("请重新输入\n");
			} while(opp != 1 && opp != 2);
		}
	}
	printf("欢迎下次再使用本系统！\n");
	}
}

/*
SqList L={{{'a',1,1.1},{'b',2,2.2},{'c',3,3.3},{'d',4,4.4}}, 4};

int main(intargc, char *argv[])
{
FILE  *fp;char filename[30];int i; 
printf("input file name: ");
scanf("%s",filename);

//写文件的方法
if ((fp=fopen(filename,"wb"))==NULL)
	{
	printf("File open erroe\n ");
	return 1;
	}
fwrite(L.elem,sizeof(ElemType),L.length,fp);
//这里是1次性写入，对于其它物理结构，可通过遍历，逐个访问数据元素
//并写入到文件中。也可以先写入表长，再写入全部元素，这样读入会更方便
fclose(fp);
	
//读文件的方法
L.length=0;
if ((fp=fopen(filename,"rb"))==NULL)
	{
	printf("File open erroe\n ");
	 return 1;
	}
while(fread(&L.elem[L.length],sizeof(ElemType),1,fp))
L.length++;
//这里从文件中逐个读取数据元素恢复顺序表，对于不同的物理结构，可通过读//取的数据元素恢复内存中的物理结构。
fclose(fp);
return 0;
}
*/

/*

#include "def.h"
#include "string.h"

#include "stu.h"
int main()
{
SqList L;
FILE *fp;
//char FileName[30];
int f,i=0,j,e;
//strcpy(FileName,"src/step13/list.dat");
scanf("%d",&f);
if (!f)
{
    	L.elem=NULL;
   		j=SaveList(L,"src/step13/list.dat");
   		if (j!=INFEASIBLE) printf("不能对不存在的线性表进行写文件操作！");
    	else 
      {
    		 L.elem=(ElemType *) malloc(sizeof(ElemType));
   			 j=LoadList(L,"src/step13/list.dat");
   			 if (j!=INFEASIBLE) printf("不能对已存在的线性表进行读文件操作！");
    	    else printf("INFEASIBLE"); 
    		 free(L.elem);
      }
}
else
     {
        L.elem=(ElemType *) malloc(sizeof(ElemType)*LIST_INIT_SIZE);
        L.length=0;
        L.listsize= LIST_INIT_SIZE;
        scanf("%d",&e);
        while (e)
        {
            L.elem[i++]=e;
            scanf("%d",&e);
        }
        L.length=i;
        j=SaveList(L,"src/step13/list.dat");
   		free(L.elem); 
		L.elem=NULL;
        j=LoadList(L,"src/step13/list.dat");
        printf("%d\n",L.length);
        for(i=0;i<L.length;i++) 
            printf("%d ",L.elem[i]);
     }
return 1;
}
*/