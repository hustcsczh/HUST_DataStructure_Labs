#include"funct_1.h"

int main(void)
{
	lists.length = 0;
	lists.listsize = 10;
	for (int i = 0; i < 10;i++)
		lists.elem[i].L.elem = NULL;
	int op=1;
	SqList L;
	int count = 0;
	while(op)
	{
		My_print();
		scanf("%d", &op);
		getchar();
		switch(op)
	   	{
		case 0:
			break;
		case 1:

			{
				printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				if (LocateList(lists, name))
					printf("线性表 %s 已存在\n",name);
				else
				{
					AddList(lists, name);
					printf("线性表 %s 创建成功!\n",name);
				}
				printf("点击Enter进行下一步");getchar();
				break;
			}
		case 2:
			{
				printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				int result=DestroyList(lists.elem[id].L);
		   		if(result==OK)
					printf("线性表 %s 销毁成功！\n",name);
		   		else 
					printf("线性表 %s 不存在！\n",name);
	   			printf("点击Enter进行下一步");
				getchar();
				break;
			}
		case 3:
			{
				printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				int result=ClearList(lists.elem[id].L);
				if (LocateList(lists, name)==0)
					printf("线性表 %s 不存在\n",name);
		   		if(result==OK)
			   		printf("线性表 %s 清空成功！\n",name);
	            printf("点击Enter进行下一步");
				getchar();
			    break;
			}
		case 4:
		   	{
				printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("线性表 %s 不存在\n",name);
				else
				{
					int result=ListEmpty(lists.elem[id].L);
					if(result==TRUE)
			   			printf("线性表 %s 是空的！\n",name);
		   			else 
						printf("线性表 %s 非空！\n",name);
				}
	   			printf("点击Enter进行下一步");
				getchar();
				break;
			}
		case 5:
			{
				printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				int result=ListLength(lists.elem[id].L);
		   	    if (LocateList(lists, name)==0)
					printf("线性表 %s 不存在\n",name);
		   	    else 
                    printf("线性表 %s 长度为 %d\n",name,result);
	            printf("点击Enter进行下一步");
				getchar();
			break;
			}
		case 6:
		   	{
				printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("线性表 %s 不存在\n",name);
				else
				{
				int i = 0,e;
	        	printf("输入你想获取的第i个元素: ");
		   		scanf("%d", &i);
				int result=GetElem(lists.elem[id].L,i,e);
		   		if (result!=OK)
			   	printf("获取失败\n");
		   		else 
				printf("第 %d 个元素是 %d\n", i, e);
				}
	        	printf("点击Enter进行下一步");
				getchar();
				getchar();
				break;
		   	}
		case 7:
		  	{
				printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("线性表 %s 不存在\n",name);
				else
				{
			    printf("输入你想查找的元素e的大小: ");
			    int e1;
			    scanf("%d", &e1);
			    int result = LocateElem(lists.elem[id].L, e1);
			    if(result==0)
				    printf("表中不存在元素%d\n", e1);
		        else
			        printf("%d 的序号是: %d\n", e1, result);
				}
			    printf("点击Enter进行下一步");
			    getchar();getchar();
			    break;
		  	}
		case 8:
		  	{
				printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("线性表 %s 不存在\n",name);
				else
				{
			    printf("输入你想查找的元素e的前驱: ");
			    int e2=0, pre=0;
			    scanf("%d", &e2);
			    int result =PriorElem(lists.elem[id].L,e2,pre);
			    if(result==ERROR)
				    printf("%d的前驱不存在\n",e2);
		   	    else
			        printf("%d 的前驱是: %d\n", e2, pre);
				}
			    printf("点击Enter进行下一步");
			    getchar();getchar();
			    break;
		 	}
		case 9:
		  	{
				printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("线性表 %s 不存在\n",name);
				else
				{
	        printf("输入你想查找的元素e的后继: ");
			int e=0,next=0;
			scanf("%d", &e);
			int result =NextElem(lists.elem[id].L,e,next);
			if(result==ERROR)
				printf("%d的后继不存在\n",e);
		   	else
			   printf("%d 的后继是: %d\n", e, next);
				}
			printf("点击Enter进行下一步");
			getchar();getchar();
			break;
		  	}
		case 10:
		  	{
				printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("线性表 %s 不存在\n",name);
				else
				{
				printf("输入你想插入的元素e和位置i:  ");
				int i, e;
				scanf("%d %d", &e, &i);
				int result = ListInsert(lists.elem[id].L, i, e);
		   		if(result==ERROR)
			   printf("插入位置错误\n");
		   		else
			   printf("插入操作成功\n");
				}
			printf("点击Enter进行下一步");
			getchar();
			getchar();
			break;
		  	}
		case 11:
		  	{
				printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("线性表 %s 不存在\n",name);
				else
				{
			printf("输入你想删除的元素的位置i:  ");
			int i, e;
			scanf("%d",&i);
			int result = ListDelete(lists.elem[id].L, i, e);
			if (result == ERROR)
				 printf("删除位置错误\n");
			else
				 printf("删除操作成功，删除的元素是 %d\n",e);
				}
			printf("点击Enter进行下一步");
			getchar();
			getchar();
			break;
			}
		case 12:
		  	{
			printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
		   	int result=ListTraverse(lists.elem[id].L);
			if(result==INFEASIBLE)
			   printf("线性表 %s 未初始化！\n",name);
			printf("点击Enter进行下一步");
			getchar();
			break;
		  	}
		case 13:
		{
			printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("线性表 %s 不存在\n",name);
				else
				{
			int result=MaxSubArray(lists.elem[id].L);
			if(result==INFEASIBLE)
			   printf("线性表 %s 是空表！\n",name);
			else
				printf("连续子数组的最大和为：%d\n", result);
				}
			printf("点击Enter进行下一步");
			getchar();
			break;
		}
	   	case 14:
		{
			printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				if (LocateList(lists, name)==0)
					printf("线性表 %s 不存在\n",name);
				else
				{
			int K;
			printf("请输入数组和 K 的值：");
			scanf("%d", &K);
			getchar();
			int result=SubArrayNum(lists.elem[id].L,K);
			if(result==ERROR)

			   printf("不存在！\n");
			else
				printf("和为 %d 的子数组有 %d 个\n", K, result);
				}
			printf("点击Enter进行下一步");
			getchar();
			break;
		}
		case 15:
		{
			printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
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
			printf("%d", lists.length);
			scanf("%d", &opp);
			getchar();
			FILE *fp;char filename[50];int i;
			if(opp==1)
			{
				printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);int id=LocateList(lists,name)-1;
				getchar();
				strcpy(filename, "D:/HUST-DataStructure-Labs/lab1/data/3.dat");
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
				printf("请输入线性表的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				if (LocateList(lists, name)==0)
				{
					printf("可选的文件地址： D:/HUST-DataStructure-Labs/lab1/data/1.dat   or  D:/HUST-DataStructure-Labs/lab1/data/2.dat\n");
					printf("请输入文件路径: ");
					gets(filename);
					lists.elem[lists.length].L.elem = NULL;
					L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
					L.length=0;
					L.listsize=LIST_INIT_SIZE;
					strcpy(lists.elem[lists.length].name,name);
					int result=LoadList(lists.elem[lists.length].L, filename);
					ListTraverse(lists.elem[lists.length].L);
					if(result==ERROR)
						printf("文件地址错误\n");
					else
						printf("已将文件内容读入线性表 %s 中\n",name);
				}
				else 
					printf("线性表 %s 已初始化\n",name);
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

