#include"func_3.h"
int main(void)
{
	lists.length = 0;
	lists.listsize = LISTINCREMENT;
	for (int i = 0; i < LISTINCREMENT;i++)
		lists.elem[i].T= NULL;
    BiTree T;
    TElemType e;
	int op=1;
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
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				if (check(name)!=-1)
					printf("二叉树 %s 已存在",name);
				else
				{
                    BiTree T;
                    TElemType e;
					DEF definition[100];
					int ans,i=0,key;
					printf("按definition输入二叉树T\n");
                    do {
                    	scanf("%d %d %s",&definition[i].pos,&definition[i].data.key,definition[i].data.others);
                    } while (definition[i++].pos);
                    ans=CreateBiTree(T,definition);
                    lists.elem[lists.length].T=T;
	                strcpy(lists.elem[lists.length].name,name);
	                lists.length++;
					printf("二叉树 %s 创建成功!",name);
                    PreOrderTraverse(T, visit);
                    InOrderTraverse(T, visit);
				}
                getchar();
                printf("\n点击Enter进行下一步");getchar();
				break;
			}
		case 2:
			{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else{
					int result=DestroyBiTree(lists.elem[id].T);
                    lists.elem[id].T = NULL;
                    lists.length--;
                    if(result==OK)
						printf("二叉树 %s 销毁成功！\n",name);
		   			else 
						printf("二叉树 %s 不存在！\n",name);
				}
	   			printf("点击Enter进行下一步");
				getchar();
				break;
				
			}
		case 3:
			{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else{
					int result=ClearBiTree(lists.elem[id].T);
			   		printf("二叉树 %s 清空成功！\n",name);
				}
	            printf("点击Enter进行下一步");
				getchar();
			    break;
			}
		case 4:
		   	{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else{
					int result=BiTreeEmpty(lists.elem[id].T);
					if(result==ERROR)
			   			printf("二叉树 %s 是空的！\n",name);
		   			else 
						printf("二叉树 %s 非空！\n",name);
				}
	   			printf("点击Enter进行下一步");
				getchar();
				break;
			}
		case 5:
			{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else{
					int result=BiTreeDepth(lists.elem[id].T);
                	printf("二叉树 %s 深度为 %d\n",name,result);
				}
	            printf("点击Enter进行下一步");
				getchar();
				break;
			}
		case 6:
		   	{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else{
					KeyType e;
					printf("输入你想查找的节点的key: ");
		   			scanf("%d", &e);
					getchar();
					BiTNode *p=LocateNode(lists.elem[id].T,e);
					if(p) printf("%d,%s",p->data.key,p->data.others);
					else printf("不存在该结点");
				}
	        	printf("\n点击Enter进行下一步");
				getchar();
				break;
		   	}
		case 7:
		  	{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else{
			    	printf("输入你想赋值的节点的e和其value:  ");
					TElemType value;
					int e1;
					scanf("%d", &e1);
					getchar();
					scanf("%d %s", &value.key,value.others);
					getchar();
					int result = Assign(lists.elem[id].T, e1,value);
			    	if(result==ERROR)
				    	printf("赋值操作失败\n");
		        	else
			        	printf("赋值成功\n");
				}
				LevelOrderTraverse(lists.elem[id].T,visit);
			    printf("\n点击Enter进行下一步");
			    getchar();
			    break;
		  	}
		case 8:
		  	{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else{
			    	printf("输入你想查找的节点e的兄弟节点: ");
					int e;
					scanf("%d", &e);
					getchar();
					BiTree result =GetSibling(lists.elem[id].T,e);
			    	if(result==NULL)
				    	printf("%d的兄弟节点不存在\n",e);
		   	    	else
			        	printf("%d 的兄弟节点是: %d %s\n", e,result->data.key,result->data.others);
				}
			    printf("点击Enter进行下一步");
			    getchar();
			    break;
		 	}
		case 9:
		  	{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else{
	        		printf("输入你想插入的节点的位置 e LR 以及要插入的节点c的key和others: ");
					int e,LR;
					TElemType value;
					scanf("%d %d %d %s", &e, &LR, &value.key, value.others);
					getchar();
					int result =InsertNode(lists.elem[id].T,e,LR,value);
					if(result==ERROR)
						printf("赋值操作失败\n");
		   			else{
			   			printf("赋值操作成功\n");
						LevelOrderTraverse(lists.elem[id].T,visit);
					}
				}
				printf("\n点击Enter进行下一步");
				getchar();
				break;
		  	}
		case 10:
		  	{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else{
					printf("输入你想删除的节点的关键字e:  ");
					KeyType e;
					scanf("%d", &e);getchar();
					int result = DeleteNode(lists.elem[id].T,e);
		   			if(result==ERROR)
			   			printf("删除错误\n");
		   			else{
			   			printf("删除成功\n");
						LevelOrderTraverse(lists.elem[id].T,visit);
					}
				}
				printf("\n点击Enter进行下一步");
				getchar();
				break;
		  	}
		case 11:
		  	{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else
					PreOrderTraverse(lists.elem[id].T, visit);
				printf("\n点击Enter进行下一步");
				getchar();
				break;
			}
		case 12:
		  	{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else
		   			InOrderTraverse(lists.elem[id].T,visit);
				printf("\n点击Enter进行下一步");
				getchar();
				break;
		  	}
		case 13:
			{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else{
					printf("\n后序遍历--------------------------\n");
		   			PostOrderTraverse(lists.elem[id].T,visit);
				}
				printf("\n点击Enter进行下一步");
				getchar();
				break;
			}
	   	case 14:
			{ 
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else
		   			LevelOrderTraverse(lists.elem[id].T,visit);
				printf("\n点击Enter进行下一步");
				getchar();
				break;
			}
		case 15:
			{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else{
					int result = MaxPathSum(lists.elem[id].T);
					printf("最大路径和为：%d\n", result);
				}
			printf("点击Enter进行下一步");
			getchar();
			break;
		    }
		case 16:
			{
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else{
					printf("请输入两个节点的关键字e1 e2 : ");
					KeyType e1, e2;
					scanf("%d %d", &e1, &e2);
					getchar();
					BiTree result = LowestCommonAncestor(lists.elem[id].T,e1,e2);
					printf("最近的公共祖先为：%d %s\n", result->data.key,result->data.others);
				}
				printf("点击Enter进行下一步");
				getchar();
				break;
			}
		case 17:
		    {
			    printf("请输入二叉树的 name: ");
			    char name[10];
			    scanf("%s", name);
			    getchar();
			    int id=check(name);
			    if(id==-1) 
				    printf("二叉树 %s 不存在\n",name);
			    else{
				    InvertTree(lists.elem[id].T);
				    printf("二叉树翻转成功\n");
					LevelOrderTraverse(lists.elem[id].T,visit);
			    }
			    printf("点击Enter进行下一步");
			    getchar();
			    break;
		    }
		case 18:
		{
			int opp;
			do{
			printf("请选择操作输入 0.退出系统  1. 表示将二叉树存入文件， 2. 表示将文件读入二叉树：");
			scanf("%d", &opp);
			getchar();
			FILE *fp;
			char filename[50];int i;
			if(opp==1){
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("二叉树 %s 不存在\n",name);
				else{
					strcpy(filename, "D:/HUST-DataStructure-Labs/lab3/data/3.dat");
					int result = SaveBiTree(lists.elem[id].T, filename);
					if(result==INFEASIBLE)
						printf("二叉树为空\n");
					else
						printf("成功存入路径为 D:/HUST-DataStructure-Labs/lab3/data/3.dat 的文件中\n");
				}
				printf("点击Enter进行下一步");
				getchar();
			}
			else if(opp==2){
				printf("请输入二叉树的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id!=-1) 
					printf("二叉树 %s 已存在\n",name);
				else{
					printf("可选的文件地址： D:/HUST-DataStructure-Labs/lab3/data/1.dat   or  D:/HUST-DataStructure-Labs/lab3/data/2.dat");
					printf("请输入文件路径: ");
					gets(filename);
					T = NULL;
					int result=LoadBiTree(T,filename);
					if(result==INFEASIBLE)
						printf("文件地址错误\n");
					else
						printf("已将文件内容读入二叉树 %s 中\n",name);
					LevelOrderTraverse(T, visit);
					lists.elem[lists.length].T=T;
	                strcpy(lists.elem[lists.length].name,name);
					lists.length++;
				}
				printf("\n点击Enter进行下一步");
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
