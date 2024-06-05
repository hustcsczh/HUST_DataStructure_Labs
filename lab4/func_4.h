#include"def_4.h"
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
{
int i=0,j,one,two;
VertexType e;
do {
    G.vertices[i].data=V[i];
    G.vertices[i].firstarc=NULL;
} while (V[i++].key!=-1);
G.vexnum=i-1;
i=0;
while (VR[i][0]!=-1) {
    ArcNode *p;
    for(j=0;j<G.vexnum;j++)
        if (VR[i][0]==G.vertices[j].data.key)
        {
            one=j; break;
        }
    for(j=0;j<G.vexnum;j++)
        if (VR[i][1]==G.vertices[j].data.key)
        {
            two=j; break;
        }
    p=(ArcNode*)malloc(sizeof(ArcNode));    
    p->adjvex=two;p->nextarc=G.vertices[one].firstarc;G.vertices[one].firstarc=p;  
    p=(ArcNode*)malloc(sizeof(ArcNode));    
    p->adjvex=one;p->nextarc=G.vertices[two].firstarc;G.vertices[two].firstarc=p;  
    i++;
}
    return OK;
}
status DestroyGraph(ALGraph &G)
/*销毁无向图G,删除G的全部顶点和边*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < G.vexnum;i++)
    {
        ArcNode *p;
        while (G.vertices[i].firstarc)
	    {
		    p = G.vertices[i].firstarc;
            G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
            free0(p);
            p = NULL;
        }
    }
    G.arcnum = G.vexnum=0;
    return OK;
    /********** End **********/
}
int LocateVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i<G.vexnum;i++)
    {
        if(u==G.vertices[i].data.key)
            return i;
    }
    G.vexnum--;
    return -1;
    /********** End **********/
}
status PutVex(ALGraph &G,KeyType u,VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (LocateVex(G, value.key)!= -1)
        return ERROR;
    int i=LocateVex(G,u);
    if(i!=-1){
        G.vertices[i].data.key=value.key;
        strcpy(G.vertices[i].data.others, value.others);
        return OK;
    }
    return ERROR;
    /********** End **********/
}
int NextAdjVex(ALGraph G,KeyType v,KeyType w)
{
    int i =LocateVex(G, v);
    if(i==-1)
        return -1;
    int W_pos = LocateVex(G, w);
    if(W_pos==-1)
        return -1;
    ArcNode *p;
    p = G.vertices[i].firstarc;
    while (p)
    {
        if(p->adjvex==W_pos){
            if(p->nextarc)
                return p->nextarc->adjvex;
            return -1;
        }
        p = p->nextarc;
    }
    return -1;
    /********** End **********/
}
status InsertVex(ALGraph &G,VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(G.vexnum>=20)
        return ERROR;
    int i =LocateVex(G, v.key);
    if(i!=-1)
        return ERROR;
    G.vertices[G.vexnum].data.key = v.key;
    strcpy(G.vertices[G.vexnum].data.others, v.others);
    G.vexnum++;
    return OK;
    /********** End **********/
}
status DeleteVex(ALGraph &G,KeyType v)
{
    int pos =LocateVex(G, v);
    if(pos==-1)
        return ERROR;
    if(pos==0&&G.vexnum==1)
        return ERROR;
    ArcNode *p;
    int j = 0;
    while (G.vertices[pos].firstarc)
	{
		p = G.vertices[pos].firstarc;
        G.vertices[pos].firstarc = G.vertices[pos].firstarc->nextarc;
        free0(p);
        j++;
        p = NULL;
    }
    for (int i=pos; i < G.vexnum-1;i++)
        G.vertices[i] = G.vertices[i + 1];
    G.vexnum--;
    for (int i = 0; i < G.vexnum;i++)
    {
        if(G.vertices[i].firstarc){
            if(G.vertices[i].firstarc->adjvex==pos)
            {
                p = G.vertices[i].firstarc;
                G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
                free0(p);
            }
            else{
                ArcNode *p1;
                p = G.vertices[i].firstarc;
                p1 = p->nextarc;
                while (p1)
                {
                    if(p1->adjvex==pos){
                        p->nextarc = p1->nextarc;
                        free0(p1);
                        p1 = p;
                    }
                    else{
                        p= p1;
                        p1 = p1->nextarc;
                    }
                }
            }
        }
    }
    G.arcnum -= j;
    for (int i = 0; i<G.vexnum;i++)
    {
        p = G.vertices[i].firstarc;
        while (p)
        {
            if(p->adjvex>pos)
                p->adjvex--;
            p = p->nextarc;
        }  
    }
    return OK;
    /********** End **********/
}
status InsertArc(ALGraph &G,KeyType v,KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int v_pos =LocateVex(G, v);
    if(v_pos==-1)
        return ERROR;
    int w_pos = LocateVex(G, w);
    if(w_pos==-1)
        return ERROR;
    ArcNode *p;
    p = G.vertices[v_pos].firstarc;
    while (p)
    {
        if(p->adjvex==w_pos){
            return ERROR;
        }
        p = p->nextarc;
    }
    ArcNode *a, *b;
    a = (ArcNode *)malloc(sizeof(ArcNode));
    b = (ArcNode *)malloc(sizeof(ArcNode));
    a->adjvex = w_pos;
    b->adjvex = v_pos;
    p = G.vertices[v_pos].firstarc;
    G.vertices[v_pos].firstarc = a;
    a->nextarc = p;
    p = G.vertices[w_pos].firstarc;
    G.vertices[w_pos].firstarc = b;
    b->nextarc = p;
    G.arcnum++;
    return OK;
    /********** End **********/
}
status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int v_pos =LocateVex(G, v);
    if(v_pos==-1)
        return ERROR;
    int w_pos = LocateVex(G, w);
    if(w_pos==-1)
        return ERROR;
    ArcNode *p;
    int flag = 1;
    if(G.vertices[v_pos].firstarc){
        if(G.vertices[v_pos].firstarc->adjvex==w_pos)
        {
            p = G.vertices[v_pos].firstarc;
            G.vertices[v_pos].firstarc = G.vertices[v_pos].firstarc->nextarc;
            free0(p);
        }
        else{
            ArcNode *p1;
            p = G.vertices[v_pos].firstarc;
            p1 = p->nextarc;
            while (p1)
            {
                if(p1->adjvex==w_pos){
                    p->nextarc = p1->nextarc;
                    free0(p1);
                    flag = 0;
                    p1 = p;
                    break;
                }
                else{
                    p= p1;
                    p1 = p1->nextarc;
                }
            }
            if(flag)
                return ERROR;
        }
    }
    else
        return ERROR;
    if(G.vertices[w_pos].firstarc){
        if(G.vertices[w_pos].firstarc->adjvex==v_pos)
        {
            p = G.vertices[w_pos].firstarc;
            G.vertices[w_pos].firstarc = G.vertices[w_pos].firstarc->nextarc;
            free0(p);
        }
        else{
            ArcNode *p1;
            p = G.vertices[w_pos].firstarc;
            p1 = p->nextarc;
            while (p1)
            {
                if(p1->adjvex==v_pos){
                    p->nextarc = p1->nextarc;
                    free0(p1);
                    flag = 0;
                    p1 = p;
                    break;
                }
                else{
                    p= p1;
                    p1 = p1->nextarc;
                }
            }
            if(flag)
                return ERROR;
        }
        G.arcnum--;
    }
    else
        return ERROR;
    return OK;
    /********** End **********/
}
int FirstAdjVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i = LocateVex(G, u);
    if(i==-1)
        return -1;
    return G.vertices[i].firstarc->adjvex;
    /********** End **********/
}
void visit(VertexType v)
{
    printf(" %d %s",v.key,v.others);
}
void DFS(ALGraph G, int v, bool visited[], void(*visit) (VertexType))
{
    visited[v]=true;
    visit(G.vertices[v].data);
    for (ArcNode *p = G.vertices[v].firstarc; p;p=p->nextarc)
        if(!visited[p->adjvex])
            DFS(G, p->adjvex, visited, visit);
}
status DFSTraverse(ALGraph &G, void (*visit) (VertexType))
{
    printf("--------深度优先搜索---------\n");
    bool visited[G.vexnum];
    for(int v=0; v<G. vexnum; v++) //初始化各顶点未访问状态
    visited[v]=false;
    for(int v=0; v<G. vexnum; v++)
        if(!visited[v])
        DFS(G, v, visited, visit);
    return OK;
}
void iniQueue(QUEUE &Q)
//该函数实现初始化Q
{
/***************begin***************/
    Q.front = 0;
    Q.length = 0;
    /*************** end ***************/
}
int enQueue(QUEUE &Q,ArcNode* e)
//将元素e入队Q。成功入栈返回1，否则返回0
{
/***************begin***************/
    if(Q.length==MAXLENGTH||Q.front<0)
        return 0;
    Q.elem[Q.front+Q.length]=e;
    Q.length++;
    return 1;
    /*************** end ***************/
}
int deQueue(QUEUE &Q, ArcNode** e)
//将Q队首元素出队，赋值给e。成功出队返回1，否则返回0
{
/***************begin***************/
    if(Q.length<=0||Q.front<0||Q.front>MAXLENGTH-1)
        return 0;
    static int i = 0;
    *e = Q.elem[Q.front];
    for (int i = 0; i < Q.length-1;i++)
    {
        Q.elem[Q.front+i] = Q.elem[Q.front + 1+i];
    }
    Q.length--;
    return 1;
    /*************** end ***************/
}
status BFSTraverse(ALGraph G, void(*visit) (VertexType))
{
    printf("----------广度优先搜索----------\n");
    bool visited [MAXLENGTH];
    for(int v=0; v<G. vexnum; v++) visited[v]=false;
    QUEUE Q; 
    iniQueue(Q) ; //队列Q初始化
    for(int v=0; v<G. vexnum; v++) //按顶点位置序号依次选择顶点
        if(!visited[v]){ 
            visit(G.vertices[v].data);
            visited[v] = true;
            enQueue(Q, G.vertices[v].firstarc);
            while(Q.length)
            {
                ArcNode *p;
                deQueue(Q, &p);
                if(p){
                if(!visited[p->adjvex]){
                    visit(G.vertices[p->adjvex].data);
                    visited[p->adjvex]=true;
                }
                for (; p;p=p->nextarc)
                    if(!visited[p->adjvex]) {
                        visited[p->adjvex]=true;
                        visit(G.vertices[p->adjvex].data);
                        enQueue(Q, G.vertices[p->adjvex].firstarc);
                    }
                }
            }
        }
    return OK;
}   
status SaveGraph(ALGraph G, char FileName[])
{
    FILE *fp=fopen(FileName,"w");
    for (int i = 0; i < G.vexnum;i++)
    {
        fprintf(fp, "%d %s ", G.vertices[i].data.key, G.vertices[i].data.others);
    }
    fprintf(fp, "%d %d\n ", -1, -1);
    for (int i = 0; i < G.vexnum;i++)
    {
        ArcNode *p = G.vertices[i].firstarc;
        while (p)
        {
            fprintf(fp, "%d ", p->adjvex);
            p = p->nextarc;
        }
        fprintf(fp, "%d\n ",-1);
    }
    fprintf(fp, "%d %d", -1, -1);
    fclose(fp);
    return OK;
}
status LoadGraph(ALGraph &G, char FileName[])
{
    FILE *fp=fopen(FileName,"r");
    int a, i = 0, j = 0, count = 0;
    fscanf(fp, "%d ", &a);
    while (a!=-1)
    {
        G.vertices[i].data.key = a;
        fscanf(fp, "%s ", G.vertices[i].data.others);
        G.vertices[i++].firstarc = NULL;
        fscanf(fp, "%d ", &a);
    }
    fscanf(fp, "%d ", &a);
    for (; j < i;j++){
        fscanf(fp, "%d ", &a);
        if(a==-1)
            break;
        ArcNode *p;
        p= (ArcNode *)malloc(sizeof(ArcNode));
        count++;
        p->adjvex = a;
        p->nextarc = NULL;
        G.vertices[j].firstarc = p;
        fscanf(fp, "%d ", &a);
        while (a != -1)
        {
            ArcNode *p1;
            p1= (ArcNode *)malloc(sizeof(ArcNode));
            count++;
            p1->adjvex = a;
            p1->nextarc =NULL;
            p->nextarc = p1;
            p = p1;
            fscanf(fp, "%d ", &a);
        }
    }
    G.vexnum=i;
    G.arcnum = count;
    return OK;
}
void My_print(void)
{
         system("cls");
	    printf("      Menu  \n");
        printf("-------------------------------------------------\n");
        printf("1.CreateCraph   7.  InsertVex\n");
	  	printf("2.DestroyGraph  8.  DeleteVex\n");
	  	printf("3.ClearGraph    9.  InsertArc\n");
        printf("4.PutVex        10. DeleteArc\n");
        printf("5.FirstAdjVex   11. DFSTraverse\n");
        printf("6.NextAdjVex    12. BFSTraverse\n");
		printf("-------------------------------------------------\n");
        printf("13.VerticesSetLessThanK\n");
        printf("14.ShortestPathLength\n");
        printf("15ConnectedComponentsNums\n");
        printf("16.Save_in_file\n");
        printf("0.Exit\n");
        printf("-------------------------------------------------\n");
		printf("请选择你的操作[0~16]:"); 
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
/*
（1）距离小于k的顶点集合：函数名称是VerticesSetLessThanK(G,v,k)，初始条件是图G存在；操作结果是返回与顶点v距离小于k的顶点集合；
（2）顶点间最短路径和长度：函数名称是ShortestPathLength(G,v,w); 初始条件是图G存在；操作结果是返回顶点v与顶点w的最短路径的长度；
（3）图的连通分量：函数名称是ConnectedComponentsNums(G)，初始条件是图G存在；操作结果是返回图G的所有连通分量的个数；
*/

status VerticesSetLessThanK(ALGraph G,KeyType v, int k)
{
    memset(less, -1, sizeof(less));
    QUEUE q;
    iniQueue(q);
    int pos_v = LocateVex(G,v);
    int distance = 1, count= 0,m=0;
    int visited_less[10];
    memset(visited_less, 0, sizeof(visited_less));
    for (ArcNode *p = G.vertices[pos_v].firstarc; p;p=p->nextarc)
    {
        less[count++] = p->adjvex;
        visited_less[p->adjvex] = 1;
    }
    distance++;
    while (distance<k)
    {
        int visited[10];
        memset(visited, 0, sizeof(visited));
        m = 0;
        for (int j=0;j <= count-1;j++)
        {
            for (ArcNode *p = G.vertices[less[j]].firstarc;p;p=p->nextarc)
            {
                if(p->adjvex!=pos_v&&!visited[p->adjvex]){
                    visited[p->adjvex] = 1;
                    less_k[m++] = p->adjvex;
                }
            }
        }
        while (--m>=0){
            if(visited_less[less_k[m]]==0)
                less[count++] = less_k[m];
        }
        distance++;
    }
    if(less[0]!=-1)
        return 1;
    return -1;
}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
status find(ALGraph G,ArcNode* p,KeyType w,int visited[])
{
    if(G.vertices[p->adjvex].data.key==w)
        return 1;
    int i = 0;
    int result[5] = {100,100,100,100,100};
    for (ArcNode *p1 = G.vertices[p->adjvex].firstarc; p1&&visited[p1->adjvex]==0;p1=p1->nextarc)
    {
        if(!visited[p1->adjvex]){
            if(G.vertices[p1->adjvex].data.key!=w)
                visited[p1->adjvex] = 1;
            result[i++]=find(G, p1, w, visited);
        }
    }
    qsort(result, i, sizeof(int), cmpfunc);
    return 1+result[0];
}
status ShortestPathLength(ALGraph G,KeyType v, KeyType w)
{
    int minpath=100;
    ArcNode *p = G.vertices[LocateVex(G, v)].firstarc;
    for (; p;p=p->nextarc){
        memset(visited, 0, sizeof(visited));
        visited[LocateVex(G,v)] = 1;
        visited[p->adjvex] = 1;
        int result = find(G,p,w,visited);
        minpath = result < minpath ? result : minpath;
    }
    return minpath;
}
status ConnectedComponentsNums(ALGraph G)
{   
    bool visited [MAXLENGTH];
    int times = 0;
    for(int v=0; v<G. vexnum; v++) visited[v]=false;
    QUEUE Q; 
    iniQueue(Q) ; //队列Q初始化
    for(int v=0; v<G. vexnum; v++) //按顶点位置序号依次选择顶点
        if(!visited[v]){
            times++;
            visited[v] = true;
            enQueue(Q, G.vertices[v].firstarc);
            while(Q.length)
            {
                ArcNode *p;
                deQueue(Q, &p);
                if(p){
                    for (; p;p=p->nextarc)
                        if(!visited[p->adjvex]) {
                            visited[p->adjvex]=true;
                            enQueue(Q, G.vertices[p->adjvex].firstarc);
                        }
                }
            }
        }
    return times-1;
}

