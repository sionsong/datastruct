#include<iostream>
using namespace std;

//链式队列
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode,*LinkList;

//队列初始化
void Init(LinkList &L)
{
    L = new LinkNode;
    L->next = NULL;
}

//判断队列是否为空
bool IsEmpty(LinkList L)
{
    return L->next == NULL;
}

//入队
void EnQueue(LinkList &L, int x)
{
    LinkNode *s = new LinkNode;
    s->data = x;
    s->next = NULL;
    LinkNode *p = L;
    while(p->next != NULL)
        p = p->next;
    p->next = s;
}

//出队
bool DeQueue(LinkList &L, int &x)
{
    if(IsEmpty(L))
        return false;
    else
    {
        LinkNode *p = L->next;
        x = p->data;
        L->next = p->next;
        delete p;
        return true;
    }
}

int main(){
    LinkList L;
    Init(L);
    EnQueue(L, 1);
    EnQueue(L, 2);
    EnQueue(L, 3);
    EnQueue(L, 4);
    EnQueue(L, 5);
    EnQueue(L, 6);
    EnQueue(L, 7);
    EnQueue(L, 8);
    int x;
    while(DeQueue(L, x))
        cout << x << " ";
    return 0;

}

