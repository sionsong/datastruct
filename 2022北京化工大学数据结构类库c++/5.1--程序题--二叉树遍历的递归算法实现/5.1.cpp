#include <stdio.h>
#include <iostream>
using namespace std;
#define ElemType char

//节点声明，数据域、左孩子指针、右孩子指针

typedef struct BiTNode
{

    char data;

    struct BiTNode *lchild, *rchild;

} BiTNode, *BiTree;

//先序建立二叉树

BiTree CreateBiTree()
{

    char ch;

    BiTree T;

    scanf("%c", &ch);
    if (ch == '-')
        return NULL;

    if (ch == '#')
        T = NULL;

    else
    {

        T = new BiTNode;

        T->data = ch;

        T->lchild = CreateBiTree();

        T->rchild = CreateBiTree();
    }

    return T; //返回根节点
}

//先序遍历二叉树

void PreOrderTraverse(BiTree T)
{

    if (T)
    {

        printf("%c", T->data);

        PreOrderTraverse(T->lchild);

        PreOrderTraverse(T->rchild);
    }
}

//中序遍历

void InOrderTraverse(BiTree T)
{

    if (T)
    {

        InOrderTraverse(T->lchild);

        printf("%c", T->data);

        InOrderTraverse(T->rchild);
    }
}

//后序遍历

void PostOrderTraverse(BiTree T)
{

    if (T)
    {

        PostOrderTraverse(T->lchild);

        PostOrderTraverse(T->rchild);

        printf("%c", T->data);
    }
}

//层序遍历
void FloorPrint(BiTree T)  //层序遍历
{
    BiTree temp[100];   //创建pTreeNode指针类型的指针数组
    int in = 0;
    int out = 0;

    temp[in++] = T;  //先保存二叉树根节点 

    while (in > out)
    {
        if (temp[out])
        {
            cout << temp[out]->data;
            temp[in++] = temp[out]->lchild;
            temp[in++] = temp[out]->rchild;
        }
        out++;
    }
}


int main()
{

    BiTree T;
    cout << "请输入二叉树的前序遍历序列,以“-”结束：" << endl;
    cout << "eg：ABDH##I##E##CF#J##G##-" << endl;
    T = CreateBiTree(); //建立
    cout << "先序遍历二叉树：" << endl;
    PreOrderTraverse(T); //输出
    cout << endl;
    cout << "中序遍历二叉树：" << endl;
    InOrderTraverse(T);
    cout << endl;
    cout << "后序遍历二叉树：" << endl;
    PostOrderTraverse(T);
    cout << endl;
    cout<<"层序遍历二叉树："<<endl;
    FloorPrint(T);
    return 0;
}