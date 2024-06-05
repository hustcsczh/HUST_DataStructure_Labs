#include"func_4.h"
int main(void)
{
	lists.length = 0;
	lists.listsize = MAXLENGTH;
	for (int i = 0; i <MAXLENGTH ;i++)
        lists.elem[i].T.vertices[i].data.key=-1;
    ALGraph T;
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
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				if (check(name)!=-1)
					printf("图 %s 已存在",name);
				else
				{
                    ALGraph T;
                    VertexType V[21];
                    KeyType VR[100][2];
                    int ans, i = 0, j = 0,key;
                    printf("输入图的VertexType V[]\n");
                    do {
                    	scanf("%d %s",&V[i].key,V[i].others);
                    } while (V[i++].key!=-1);
                    printf("输入图的keytype VR[]\n");
                    do {
                    	scanf("%d %d",&VR[j][0],&VR[j][1]);
                    } while (VR[j++][0]!=-1);
                    getchar();
                    ans=CreateCraph(T,V,VR);
                    if(ans==ERROR)
						printf("输入错误\n");
					else{
						lists.elem[lists.length].T=T;
	                	strcpy(lists.elem[lists.length].name,name);
	                	lists.length++;
						printf("图 %s 创建成功!",name);
					}
				}
                printf("\n点击Enter进行下一步");
                getchar();
				break;
			}
		case 2:
			{
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else{
					int result=DestroyGraph(lists.elem[id].T);
                    lists.elem[id].T.vertices[id].data.key=-1;
                    lists.length--;
                    if(result==OK)
						printf("图 %s 销毁成功！\n",name);
		   			else 
						printf("图 %s 不存在！\n",name);
				}
	   			printf("点击Enter进行下一步");
				getchar();
				break;
				
			}
		case 3:
			{
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else{
                    printf("输入要查找的节点 v :\n");
                    KeyType v;
                    scanf("%d", &v);
                    getchar();
                    int result=LocateVex(lists.elem[id].T,v);
			   		printf("%d %s\n",lists.elem[id].T.vertices[result].data.key,lists.elem[id].T.vertices[result].data.others);
				}
	            printf("点击Enter进行下一步");
				getchar();
			    break;
			}
		case 4:
		   	{
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else{
                    printf("输入要赋值的顶点u和要修改value\n");
                    KeyType u;
                    VertexType value;
                    scanf("%d %d %s", &u, &value.key, value.others);
                    getchar();
                    int result=PutVex(lists.elem[id].T,u,value);
					if(result==ERROR)
			   			printf("赋值操作失败\n");
		   			else 
						for(int i=0;i<lists.elem[id].T.vexnum;i++)
                             printf("%d %s\n",lists.elem[id].T.vertices[i].data.key,lists.elem[id].T.vertices[i].data.others);
				}
	   			printf("点击Enter进行下一步");
				getchar();
				break;
			}
		case 5:
			{
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);if(id==-1) 
					printf("图 %s 不存在\n",name);
				else{
                    printf("输入要查询的u的第一邻接点: ");
                    int u;
                    scanf("%d", &u);
                    getchar();
                    int result=FirstAdjVex(lists.elem[id].T,u);
                	if(result!=-1)
                        printf("%d %s\n", lists.elem[id].T.vertices[result].data.key, lists.elem[id].T.vertices[result].data.others);
                    else
                        printf("无第一邻接点\n");
                }
	            printf("点击Enter进行下一步");
				getchar();
				break;
			}
		case 6:
		   	{
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else{
					printf("输入要查询的v的相对于w下一个邻接顶点的位序 v: w: \n");
                    int v,w;
                    scanf("%d %d", &v,&w);
                    getchar();
                    int result=NextAdjVex(lists.elem[id].T,v,w);
                	if(result!=-1)
                        printf("%d %s\n", lists.elem[id].T.vertices[result].data.key, lists.elem[id].T.vertices[result].data.others);
                    else
                        printf("查找失败\n");
                }
	            printf("点击Enter进行下一步");
				getchar();
				break;
		   	}
		case 7:
		  	{
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else{
					printf("输入要插入的顶点v的key和other \n");
                    VertexType v;
                    scanf("%d %s", &v.key,v.others);
                    getchar();
                    int result=InsertVex(lists.elem[id].T,v);
                	if(result==ERROR)
                        printf("插入失败\n");
                    else
                        for(int i=0;i<lists.elem[id].T.vexnum;i++)
                            printf("%d %s\n",lists.elem[id].T.vertices[i].data.key,lists.elem[id].T.vertices[i].data.others);
                }
	            printf("点击Enter进行下一步");
				getchar();
				break;
		  	}
		case 8:
		  	{
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else{
					printf("输入要删除的顶点v\n");
                    KeyType v;
                    scanf("%d", &v);
                    getchar();
                    int result=DeleteVex(lists.elem[id].T,v);
                	if(result==ERROR)
                        printf("删除失败\n");
                    else
                        for(int i=0;i<lists.elem[id].T.vexnum;i++)
                             printf("%d %s\n",lists.elem[id].T.vertices[i].data.key,lists.elem[id].T.vertices[i].data.others);
                }
	            printf("点击Enter进行下一步");
				getchar();
				break;
		 	}
		case 9:
		  	{
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else{
					printf("输入要插入的弧 v和w\n");
                    KeyType v,w;
                    scanf("%d %d", &v,&w);
                    getchar();
                    int result=InsertArc(lists.elem[id].T,v,w);
                	if(result==ERROR)
                        printf("插入失败\n");
                    else
                       	for(int i=0;i<lists.elem[id].T.vexnum;i++)
	                    {
                            ArcNode *p=lists.elem[id].T.vertices[i].firstarc;
                            printf("%d %s",lists.elem[id].T.vertices[i].data.key,lists.elem[id].T.vertices[i].data.others);
                            while (p)
                            {
                                printf(" %d",p->adjvex);
                                p=p->nextarc;
                            }
                            printf("\n");
	                    }
                }
	            printf("点击Enter进行下一步");
				getchar();
				break;
		  	}
		case 10:
		  	{
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else{
					printf("输入要删除的弧 v和w\n");
                    KeyType v,w;
                    scanf("%d %d", &v,&w);
                    getchar();
                    int result=DeleteArc(lists.elem[id].T,v,w);
                	if(result==ERROR)
                        printf("删除失败\n");
                    else
                       	for(int i=0;i<lists.elem[id].T.vexnum;i++)
	                    {
                            ArcNode *p=lists.elem[id].T.vertices[i].firstarc;
                            printf("%d %s",lists.elem[id].T.vertices[i].data.key,lists.elem[id].T.vertices[i].data.others);
                            while (p)
                            {
                                printf(" %d",p->adjvex);
                                p=p->nextarc;
                            }
                            printf("\n");
	                    }
                }
	            printf("点击Enter进行下一步");
				getchar();
				break;
		  	}
		case 11:
		  	{
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else
                    DFSTraverse(lists.elem[id].T, visit);
                printf("\n点击Enter进行下一步");
				getchar();
				break;
			}
		case 12:
		  	{
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else
		   			BFSTraverse(lists.elem[id].T, visit);
				printf("\n点击Enter进行下一步");
                getchar();
				break;
		  	}
		case 13:
			{
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else{
                    printf("输入顶点V: 和距离k:\n");
                    KeyType v;
                    ALGraph G;
                    G = lists.elem[id].T;
                    int k;
                    scanf("%d %d", &v, &k);
                    getchar();
                    int result=VerticesSetLessThanK(G, v, k);
                    int a[20];
                    memset(a, 0, sizeof(a));
                    if(result){
                        printf("距离小于k的点有: \n");
                        int pos_v = LocateVex(G, v);
                        printf("%d %s\n", G.vertices[pos_v].data.key, G.vertices[pos_v].data.others);
                        for (int i = 0; less[i]!=-1;i++){
                            if(a[less[i]]==0){
                                printf("%d %s\n", G.vertices[less[i]].data.key, G.vertices[less[i]].data.others);
                                a[less[i]] = 1;
                            }
                        }
                    }
                    else
                        printf("不存在\n");
                }
				printf("点击Enter进行下一步");
				getchar();
				break;  
			}
	   	case 14:
			{ 
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else{
                    printf("请输入顶点v和w\n");
                    KeyType v, w;
                    scanf("%d %d", &v, &w);
                    getchar();
                    int result=ShortestPathLength(lists.elem[id].T, v, w);
                    if(result)
                        printf("最短路径长度为: %d", result);
                    else
                        printf("不存在");
                }
				printf("\n点击Enter进行下一步");
				getchar();
				break;
			}
		case 15:
			{
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else
                    printf("连通分量的个数为: %d\n", ConnectedComponentsNums(lists.elem[id].T));
			    printf("点击Enter进行下一步");
			    getchar();
			    break;
		    }
		case 16:
		{
			int opp;
			do{
			printf("请选择操作输入 0.退出系统  1. 表示将图存入文件， 2. 表示将文件读入图：");
			scanf("%d", &opp);
			getchar();
			FILE *fp;
			char filename[50];int i;
			if(opp==1){
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id==-1) 
					printf("图 %s 不存在\n",name);
				else{
					strcpy(filename, "D:/HUST-DataStructure-Labs/lab4/data/3.dat");
					int result = SaveGraph(lists.elem[id].T, filename);
					if(result==INFEASIBLE)
						printf("图为空\n");
					else
						printf("成功存入路径为 D:/HUST-DataStructure-Labs/lab4/data/3.dat 的文件中\n");
				}
				printf("点击Enter进行下一步");
				getchar();
			}
			else if(opp==2){
				printf("请输入图的 name: ");
				char name[10];
				scanf("%s", name);
				getchar();
				int id=check(name);
				if(id!=-1) 
					printf("图 %s 已存在\n",name);
				else{
					printf("可选的文件地址： D:/HUST-DataStructure-Labs/lab4/data/1.dat   or  D:/HUST-DataStructure-Labs/lab4/data/2.dat\n");
					printf("请输入文件路径: ");
					gets(filename);
                    ALGraph G;
                    int result=LoadGraph(G,filename);
					if(result==INFEASIBLE)
						printf("文件地址错误\n");
					else
						printf("已将文件内容读入图 %s 中\n",name);
					lists.elem[lists.length].T=G;
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
