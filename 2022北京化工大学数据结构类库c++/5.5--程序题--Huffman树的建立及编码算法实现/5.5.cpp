#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30

typedef struct node
{
    int data;//结点数据
    struct node *lchild,*rchild;//哈夫曼树的左右孩子指针
    struct node *next;//哈夫曼树的结点同时又是单链表的结点，next为单链表的结点指针
}BSTree_Link;//二叉树及单链表结点类型

BSTree_Link *CreateLinkList(int n)//根据叶子结点的权值生成一个升序单链表
{
    BSTree_Link *link,*p,*q,*s;
    int i;
    link=(BSTree_Link*)malloc(sizeof(BSTree_Link));//生成单链表的头结点
    s=(BSTree_Link*)malloc(sizeof(BSTree_Link));//生成单链表的第一个数据结点，同时也是哈夫曼树的叶结点
    scanf("%d",&s->data);//输入叶子结点的权值
    s->lchild=NULL;
    s->rchild=NULL;//置左、右孩子指针为空的叶结点标志
    s->next=NULL;//置单链表链尾结点标志
    link->next=s;
    for(i=2;i<=n;i++)//生成单链表剩余的n-1个数据结点
    {
        s=(BSTree_Link*)malloc(sizeof(BSTree_Link));//生成一个数据结点
        scanf("%d",&s->data);//输入叶子结点的权值
        s->lchild=NULL;
        s->rchild=NULL;//置左右孩子指针为空的叶结点标志
        q=link;//将该数据结点按升序插入到单链表中
        p=q->next;
        while(p!=NULL)
            if(s->data>p->data)//查找插入位置
            {
                q=p;
                p=p->next;
            }
            else//找到插入位置后进行插入
            {
                q->next=s;
                s->next=p;
                break;
            }
            if(s->data>q->data)//插入到链尾的处理
            {
                q->next=s;
                s->next=p;
            }
    }
    return link;//返回升序单链表的头指针结点
}

void print(BSTree_Link *h)//输出单链表
{
    BSTree_Link *p;
    p=h->next;
    while(p!=NULL)
    {
        printf("%d,",p->data);
        p=p->next;
    }
    printf("\n");
}

BSTree_Link *HuffTree(BSTree_Link *link)//生成哈夫曼树
{
    BSTree_Link *p,*q,*s;
    while(link->next!=NULL)//当单链表的数据结点非空时
    {
        p=link->next;//取出升序链表中的第一个数据结点
        q=p->next;//取出升序链表中的第二个数据结点
        link->next=q->next;//使头结点的指针指向单链表的第三个数据结点
        s=(BSTree_Link*)malloc(sizeof(BSTree_Link));//生成哈夫曼树的树枝结点
        s->data=p->data+q->data;//该树枝结点的权值为取出的二个数据结点权值之和
        s->lchild=p;//取出的第一个数据结点作为该树枝结点的左孩子
        s->rchild=q;//取出的第二个数据结点作为该树枝结点的右孩子
        q=link;//将该树枝结点按升序插入到单链表中
        p=q->next;
        while(p!=NULL)
            if(s->data>p->data)
            {
                q=p;
                p=p->next;
            }
            else
            {
                q->next=s;
                s->next=p;
                break;
            }
            if(q!=link&&s->data>q->data)//插入到链尾的处理，如果q等于link则链表为空，此时*s即为根结点
            {
                q->next=s;
                s->next=p;
            }
    }
    return s;//当单链表为空时，最后生成的树枝结点即为哈夫曼树的根节点
}

void Preorder(BSTree_Link *p)//先序遍历二叉树
{
    if(p!=NULL)
    {
        printf("%4d",p->data);//访问根结点
        Preorder(p->lchild);//访问左子树
        Preorder(p->rchild);//访问右子树
    }
}

void Inorder(BSTree_Link *p)//中序遍历二叉树
{
    if(p!=NULL)
    {
        Preorder(p->lchild);//访问左子树
        printf("%4d",p->data);//访问根结点
        Preorder(p->rchild);//访问右子树
    }
}
void HuffCode(BSTree_Link *p)//后序遍历哈夫曼树并输出哈夫曼树编码
{
    BSTree_Link *stack[MAXSIZE],*q;
    int b,i=-1,j=0,k,code[MAXSIZE];
    do//后序遍历二叉树
    {
        while(p!=NULL)//将*p结点左分支上的左孩子入栈
        {
            if(p->lchild==NULL&&p->rchild==NULL)
            {
                printf("key=%3d,code:",p->data);//输出叶结点信息
                for(k=0;k<j;k++)//输出该叶结点的哈夫曼编码
                    printf("%d",code[k]);
                printf("\n");
                j--;
            }
            stack[++i]=p;//指向当前结点的指针p入栈
            p=p->lchild;//p指向*p的左孩子
            code[j++]=0;//对应的左分支置编码0
        }
        //栈顶结点已没有左孩子或其左子树上的结点都已访问过
        q=NULL;
        b=1;//置已访问过的标记
        while(i>=0&&b)//栈stack不空且当前栈顶结点的左子树已经遍历过
        {
            p=stack[i];//取出当前栈顶存储的结点指针
            if(p->rchild==q)//当前栈顶结点*p无右孩子或*p的右孩子已访问过
            {
            i--;
            j--;
            q=p;//q指向刚访问过的结点*p
            }
    else//当前栈顶结点*p有右子树
        {
            p=p->rchild;//p指向当前栈顶结点*p的右孩子结点
            code[j++]=1;//对应的右分支置编码1
            b=0;//置右孩子结点未遍历过其右子树标记
            }
        }
    }while(i>=0);//当栈stack非空时继续遍历
}

int main()
{
    BSTree_Link *root;
    int n;
    printf("Input number of keys\n");//输入叶子结点的个数
    scanf("%d",&n);
    printf("Input keys:\n");//输入n个叶子结点的权值
    root=CreateLinkList(n);//根据叶子结点的权值生成一个升序单链表
    printf("Output list:\n");//输出所生成的升序单链表
    print(root);
    root=HuffTree(root);//生成哈夫曼树
    printf("Inorder output HuffTree:\n");//先序遍历输出哈夫曼树各结点的值
    Inorder(root);
    printf("\n");
    printf("Preorder output HuffTree:\n");//先序遍历输出哈夫曼树各结点的值
    Preorder(root);
    printf("\n");
    printf("Output Code  of HuffTree:\n");//后序遍历哈夫曼树构造并输出哈夫曼编码
    HuffCode(root);
}