#include"def_3.h"
void iniQueue(QUEUE &Q)
{
    Q.front = 0;
    Q.length = 0;
}
status enQueue(QUEUE &Q,BiTree e)
{

    if(Q.length==MAXLENGTH||Q.front<0)
        return 0;
    Q.elem[Q.front+Q.length] = e;
    Q.length++;
    return 1;
}
status deQueue(QUEUE &Q,BiTree &e)
{
    if(Q.length<=0||Q.front<0||Q.front>MAXLENGTH-1)
        return 0;
    static int i = 0;
    e = Q.elem[Q.front];
    for (int i = 0; i < Q.length-1;i++)
    {
        Q.elem[Q.front+i] = Q.elem[Q.front + 1+i];
    }
    Q.length--;
    return 1;
}

void inistack(STACK &S)
{
   S.top1=0;
}
status push(STACK &S,BiTree e)
{
    if(S.top1>=N)
        return 0;
    S.elem[S.top1] = e;
    S.top1++;
    return 1; 
}
BiTree pop(STACK &S)
{
    if(S.top1<=0)
        return 0;
    BiTree e;
    e=S.elem[S.top1-1];
    S.elem[S.top1-1] = NULL;
    S.top1--;
    return e;
}
#define free free0
#undef free
void visit(BiTree T)
{
    printf(" %d,%s",T->data.key,T->data.others);
}
void free0(void *p)
{

    if (((BiTree)p)->data.key==e)
        freed=TRUE;
    memset(p,0,sizeof(BiTNode));
    free(p);
}
status CreateBiTree(BiTree &T,DEF definition[])
{
    int i=0,j;
    static BiTNode *p[100];
	if(!definition[i].pos)
        return ERROR;
    while (j=definition[i].pos)
    {
        p[j]=(BiTNode *)malloc(sizeof(BiTNode));
        p[j]->data=definition[i].data;
        p[j]->lchild=NULL;
        p[j]->rchild=NULL;
        if (j!=1)
       		if (j%2)    p[j/2]->rchild=p[j];
       	    else    p[j/2]->lchild=p[j];
        i++;
    }
    T=p[1];
    return OK;
}
status DestroyBiTree(BiTree &T)
{
   if (T)
   {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
        T=NULL;
   }
   return OK;
}
status ClearBiTree(BiTree &T)
//将二叉树设置成空，并删除所有结点，释放结点空间
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T){
		static BiTree p = T;
        ClearBiTree(T->lchild);
        ClearBiTree(T->rchild);
        if(T!=p){
            free0(T);
            T=NULL;
        }
    }
    return OK;
    /********** End **********/
}
status BiTreeEmpty(BiTree T)
{
    if(T->lchild||T->rchild)
        return OK;
    return ERROR;
}
status BiTreeDepth(BiTree T)
{
    int left, right;
    if (T== NULL)   
        return 0;
    else
    {
        left = BiTreeDepth(T->lchild);   
        right = BiTreeDepth(T->rchild);
        return left > right ? (left+1) : (right+1);   
    }
}
BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
{
    if(T){
        if(T->data.key == e){
            return T;
        }
        BiTNode* leftResult = LocateNode(T->lchild, e);
        if(leftResult)
            return leftResult;
        BiTNode* rightResult = LocateNode(T->rchild, e);
		if(rightResult)
        	return rightResult;
    }
    return NULL;
}
status Assign(BiTree &T,KeyType e,TElemType value)
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    BiTree p, p1;
    p=(BiTNode *)malloc(sizeof(BiTNode));
    p1=(BiTNode *)malloc(sizeof(BiTNode));
    p = LocateNode(T, value.key);
    if(p&&value.key!=e)
        return ERROR;
    p1 = LocateNode(T,e);
    if(p1){
        p1->data.key = value.key;
        strcpy(p1->data.others, value.others);
        return OK;
    }
    return ERROR;
    /********** End **********/
}
BiTNode* GetSibling(BiTree T, KeyType e)   //获得兄弟节点
{
    BiTNode* p = NULL; 
    if (T) {
        if (T->lchild && T->lchild->data.key == e) {
            p = T->rchild;
            return p;
        } else if (T->rchild && T->rchild->data.key == e) {
            p = T->lchild;
            return p;
        }

        BiTNode* leftResult = GetSibling(T->lchild, e);
        if (leftResult) {
            return leftResult;
        }

        BiTNode* rightResult = GetSibling(T->rchild, e);
        if (rightResult) {
            return rightResult;
        }
    }
    return p; 
}
BiTNode* Get(BiTree T,KeyType e)          //获得双亲节点
{
	BiTNode* p = NULL; 
    if(T){
		if(T->lchild&&T->lchild->data.key==e){
			return T;
		}
        else if(T->rchild&&T->rchild->data.key==e){
            return T;
        }
        BiTNode* leftResult = Get(T->lchild, e);
        if(leftResult)
            return leftResult;
        BiTNode* rightResult = Get(T->rchild, e);
		if(rightResult)
        	return rightResult;
    }
	return p;
}
BiTNode* Getright(BiTree p)               //获得左子树最右节点 
{
    while (p)
    {
        if(p->rchild)
            p = p->rchild;
        else if(p->lchild)
            p = p->lchild;
        else
            return p;
    }
    return p;
}
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//插入结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(LocateNode(T,c.key))
        return ERROR;
    if(LR==-1){
        BiTree p1=(BiTree)malloc(sizeof(BiTNode));
        p1->data.key = c.key;
        strcpy(p1->data.others, c.others);
        p1->lchild = NULL;
        p1->rchild = T;
        T = p1;
        return OK;
    }
    BiTree p=LocateNode(T, e);
    if(p){
        BiTree p1 = (BiTree)malloc(sizeof(BiTNode));
        p1->data.key = c.key;
        strcpy(p1->data.others, c.others);
        if(LR==0){
            BiTree p2 = p->lchild;
            p->lchild = p1;
            p1->lchild = NULL;
            p1->rchild = p2;
        }
        if(LR==1){
            BiTree p2 = p->rchild;
            p->rchild = p1;
            p1->lchild = NULL;
            p1->rchild = p2;
        }
        return OK;
    }
    return ERROR;
    /********** End **********/
}
status DeleteNode(BiTree &T,KeyType e)
//删除结点
{
   if(!T) {
           return ERROR;
   }
   if(T->data.key==e){
           BiTree p=T;
           if(!T->lchild&&!T->rchild){
               T=NULL;
           }
        else if(!T->rchild){
            T=T->lchild;
        }
        else if(!T->lchild){
            T=T->rchild;
        }
        else{
            T=T->lchild;
            BiTree t=T;
            while(t->rchild){
                t=t->rchild;
            }
            t->rchild=p->rchild;
        }
        free(p);
        return OK;
   }
   return DeleteNode(T->lchild,e)||DeleteNode(T->rchild,e);
}
status PreOrderTraverse(BiTree T,void (*visit)(BiTree))       //前序遍历
{
 	printf("\n先序遍历--------------------------\n");
    STACK s;
	inistack(s);
	BiTree p;
	p = T;
	while (p||s.top1)
	{
		if (p){
			visit(p);
			push(s, p);
			p = p->lchild;
		}
		else{
            p = pop(s);
            p =p->rchild;
        }
	}
	printf("\n");
	return OK;
}
status InOrderTraverse(BiTree T,void (*visit)(BiTree))        //中序遍历
{
  
	printf("\n中序遍历--------------------------\n");
    STACK s;
	inistack(s);
    BiTree p;
    p = T;
	while (p||s.top1)
	{
		if (p){
			//visit(p);
			push(s, p);
            p = p->lchild;
		}
		else{
            p = pop(s);
            visit(p);
            p =p->rchild;
        }
	}
    return OK;
}
status PostOrderTraverse(BiTree T,void (*visit)(BiTree))      //后序遍历
{
    if (T)
    {
        PostOrderTraverse(T->lchild,visit);
        PostOrderTraverse(T->rchild,visit);
        visit(T);
    }
    return OK;
}
status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))    //层序遍历
{
	printf("\n层序遍历--------------------------\n");
    BiTree QUEUE[MAXLENGTH];
    int front = 0, rear = 0;
    if(T){
        QUEUE[rear++] = T;
    }
    while (front!=rear)
    {
        T = QUEUE[front++];
        visit(T);
        if(T->lchild)
            QUEUE[rear++] = T->lchild;
        if(T->rchild)
            QUEUE[rear++] = T->rchild;
    }
    return OK;
}
status MaxPathSum(BiTree T)
{
    if (T == NULL) {
        return 0;
    }
    int leftMax = MaxPathSum(T->lchild);
    int rightMax = MaxPathSum(T->rchild);
    int maxPath = (leftMax > rightMax ? leftMax : rightMax)+T->data.key;
    return maxPath;
}
BiTNode* LowestCommonAncestor(BiTree T,KeyType e1, KeyType e2)
{
    if(T == NULL)  
        return NULL;  
    if(T->data.key==e1 || T->data.key==e2)  
        return T;  
 
    BiTree left = LowestCommonAncestor(T->lchild, e1, e2);  
    BiTree right = LowestCommonAncestor(T->rchild, e1, e2);  
    // node1 和 node2 不存在祖先关系
    if(left != NULL && right != NULL)  
        return T; 
    // node1 和 node2 其中一个是另一个的祖先
    else if(left != NULL)  
        return left;  
    else if (right != NULL)  
        return right;  
    else   
        return NULL;  
} 
BiTNode* InvertTree(BiTree &T)
{
	if (T == NULL) {
		return NULL;
	}
	BiTree temp = T->lchild;
	T->lchild= T->rchild;
	T->rchild = temp;
	InvertTree(T->lchild);
	InvertTree(T->rchild);
	return T;
}
void PreOrderTraverse(BiTree T)
{
    if (T)
    {
        printf("%d %s",T->data.key,T->data.others);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void InOrderTraverse(BiTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        printf(" %d,%s",T->data.key,T->data.others);
        InOrderTraverse(T->rchild);
    }
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
void My_print(void)
{
       system("cls");
	    printf("      Menu  \n");
        printf("-------------------------------------------------\n");
        printf("1.  CreateBiTree	8.  GetSibling\n");
	  	printf("2.  DestroyBitree	9.  InsertNode\n");
	  	printf("3.  ClearBiTree		10. DeleteNode\n");
        printf("4.  BiTreeEmpty		11. PreOrderTraverse\n");
        printf("5.  BiTreeDepth		12. InOrderTraverse\n");
        printf("6.  LocateNode		13. PostOrderTraverse\n");
        printf("7.  Assign		14. LevelOrderTraverse\n");
		printf("-------------------------------------------------\n");
        printf("15.MaxPatSum\n");
        printf("16.LowestCommmonAncestor\n");
        printf("17.RemoveNthFromEnd\n");
        printf("18.Save_in_file\n");
        printf("0.Exit\n");
        printf("-------------------------------------------------\n");
		printf("%d个二叉树已初始化\n",lists.length);
		for (int i = 0; i < lists.length;i++)
		{
			if(lists.elem[i].T!=NULL)
				printf("%s ", lists.elem[i].name);
		}
		printf("请选择你的操作[0~18]:"); 
}
status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
	FILE *fp=fopen(FileName,"w");
	int _pos[10] = {1,1};
	DEF * def[10];
	BiTree QUEUE[MAXLENGTH];
    int front = 0, rear = 0;
	if(T)
        QUEUE[rear++] = T;
   	while (front!=rear)
    {
		T = QUEUE[front];
		def[front] = (DEF *)malloc(sizeof(DEF));
		def[front]->pos = _pos[front];
		def[front]->data.key = T->data.key;		
		strcpy(def[front]->data.others , T->data.others);
		if(T->lchild&&!T->rchild){
           	QUEUE[rear++] = T->lchild;
			_pos[rear-1] = _pos[front] * 2;
		}
		else if (T->rchild&&!T->lchild){
			QUEUE[rear++] = T->rchild;
			_pos[rear-1] = _pos[front]*2+1;
		}
		else if(T->lchild&&T->rchild){
			QUEUE[rear++] = T->lchild;
			QUEUE[rear++] = T->rchild;
			_pos[rear-2] =_pos[front]* 2;
			_pos[rear-1] = _pos[rear-2] + 1;
		}
		else
			;
		front++;
	}
	def[front] = (DEF *)malloc(sizeof(DEF));
	def[front]->pos = 0;
	def[front]->data.key = 0;
	strcpy(def[front]->data.others,"null");
	int i = 0;
	while (def[i]->data.key!=0)
	{
		fprintf(fp,"%d %d %s ", def[i]->pos, def[i]->data.key, def[i]->data.others);
		i++;
	}
	fprintf(fp,"%d %d %s ", 0, 0,"null");
	fclose(fp);
	return OK;
}
status LoadBiTree(BiTree &T,  char FileName[])
//读入文件FileName的结点数据，创建二叉树
{
	T=(BiTree)malloc(sizeof(BiTNode));
	FILE *fp=fopen(FileName,"r");
	DEF def[10];
	int a, i = -1;
	do
	{
		i++;
		fscanf(fp, "%d ", &def[i].pos);
		fscanf(fp, "%d ", &def[i].data.key);
		fscanf(fp, "%s ", def[i].data.others);
	} while (def[i].pos!=0);
    fclose(fp);
	CreateBiTree(T, def);
	return OK;
}

