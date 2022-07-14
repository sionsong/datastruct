#include<iostream>
using namespace std;

//链式栈
typedef struct Linlnode{
    int data;
    struct Linlnode *next;    
}Linlnode,*Linlnodeptr;

//初始化
Linlnodeptr init(Linlnodeptr &L){
    L = (Linlnodeptr)malloc(sizeof(Linlnode));
    L->next = NULL;
    return L;
}

//判断是否为空
bool isempty(Linlnodeptr L){
    if(L->next == NULL)
        return true;
    else
        return false;
}

//入栈
void push(Linlnodeptr &L,int x){
    Linlnodeptr s = (Linlnodeptr)malloc(sizeof(Linlnode));
    s->data = x;
    s->next = L->next;
    L->next = s;
}

//出栈
void pop(Linlnodeptr &L){
    Linlnodeptr p = L->next;
    L->next = p->next;
    free(p);
}

//取栈顶元素
int top(Linlnodeptr L){
    return L->next->data;
}

//遍历
void traverse(Linlnodeptr L){
    Linlnodeptr p = L->next;
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

//销毁
void destroy(Linlnodeptr &L){
    Linlnodeptr p = L->next;
    while(p != NULL){
        L->next = p->next;
        free(p);
        p = L->next;
    }
}

//主函数
int main(){
    Linlnodeptr L;
    init(L);
    push(L,1);
    push(L,2);
    push(L,3);
    push(L,4);
    push(L,5);
    traverse(L);
    pop(L);
    traverse(L);
    destroy(L);
    return 0;
}

