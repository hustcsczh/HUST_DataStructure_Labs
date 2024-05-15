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
    static BiTree p = T;
    if(T){
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
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    static BiTree p=NULL;
    if(T&&p==NULL){
        if(T->data.key==e)
            p = T;
        LocateNode(T->lchild,e);
        LocateNode(T->rchild, e);
    }
    return p;
    /********** End **********/
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
BiTNode* GetSibling(BiTree T,KeyType e)   //获得兄弟节点
{
    static BiTree p=NULL;
    if(T&&p==NULL){
        if(T->lchild&&T->lchild->data.key==e){
            p = T->rchild;
            return p;
        }
        else if(T->rchild&&T->rchild->data.key==e){
            p = T->lchild;
            return p;
        }
        GetSibling(T->lchild,e);
        GetSibling(T->rchild, e);
    }
    return p;
}
BiTNode* Get(BiTree T,KeyType e)          //获得双亲节点
{
    static BiTree p=NULL;
    if(T&&p==NULL){
        if(T->lchild&&T->lchild->data.key==e){
            p = T;
            return p;
        }
        else if(T->rchild&&T->rchild->data.key==e){
            p = T;
            return p;
        }
        Get(T->lchild,e);
        Get(T->rchild, e);
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
{
    BiTree p = LocateNode(T, e);// 找到要删除的节点
    if(!p)
        return ERROR;
    if(p==T){
        BiTree p2 = Getright(p->lchild);
        BiTree p3 = p->rchild ;
        T = p->lchild;
        p2->rchild=p3;
        p2->lchild = NULL;
        T->lchild = NULL;
        free0(p);
        p = NULL;
        return OK;
    }
    BiTree p1 = Get(T, e);///  其父节点
    {
        if(!p->lchild&&!p->rchild){   //度为0
            if(p1->lchild==p)
                p1->lchild = NULL;
            else
                p1->rchild = NULL;
        }
        else if(p->lchild&&!p->rchild){  //度为1
            if(p1->lchild==p)
                p1->lchild = p->lchild;
            else
                p1->rchild =p->lchild;
        }
        else if(p->rchild&&!p->lchild){  //度为1
            if(p1->lchild==p)
                p1->lchild = p->rchild;
            else
                p1->rchild =p->rchild;
        }
        else{                              //度为2
            BiTree p2, p3;
            p2 = p->lchild;
            p3 = p->rchild;
            if(p1->lchild==p)
                p1->lchild = p2;
            else
                p1->rchild = p2;
            while(p2){
                if(p2->rchild){
                    p2 = p2->rchild;
                }
                else if(p2->lchild){
                    p2 = p2->lchild;
                }
                else{
                    p2->rchild = p3;
                    BiTree p4 = Getright(p2->lchild);
                    p4->rchild = p3;
                }
            }
        }
        free0(p);
        p = NULL;
    }
    return OK;
    /********** End **********/
}
status PreOrderTraverse(BiTree T,void (*visit)(BiTree))       //前序遍历
{
    /*if (T)
    {
        visit(T);
        PreOrderTraverse(T->lchild,visit);
        PreOrderTraverse(T->rchild,visit);
    }
    return OK;*/
    //先序遍历二叉树
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
    /*if (T)
    {
        InOrderTraverse(T->lchild,visit);
        visit(T);
        InOrderTraverse(T->rchild,visit);
    }
    return OK;*/
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
	 printf("\n后序遍历--------------------------\n");
    if (T)
    {
        PostOrderTraverse(T->lchild,visit);
        PostOrderTraverse(T->rchild,visit);
        visit(T);
    }
    return OK;
    /*STACK s;
	inistack(s);
    BiTree p, p1, p2;
    p = T;
	while (p||s.top1)
	{
        if(p){
            
            push(s,p);
            p1 = p;
            p = p->lchild;
        }
        else{
            p=pop(s);
            if(p1->rchild){
                visit(p);
            }
            else{
                if(p1->rchild){
                    p = p1->rchild;
                }
                if(!p->lchild&&!p->rchild){
                    p2 = pop(s);
                    visit(p2);
                }

            }
        }*/

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
        printf(" %d,%s",T->data.key,T->data.others);
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
/*status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
   


   
}
status LoadBiTree(BiTree &T,  char FileName[])
{
   
    


    
}*/
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
		printf("%d个二叉树已初始化\n",lists.length);
		for (int i = 0; i < lists.length;i++)
		{
			if(lists.elem[i].T!=NULL)
				printf("%s ", lists.elem[i].name);
		}
		printf("请选择你的操作[0~16]:"); 
}