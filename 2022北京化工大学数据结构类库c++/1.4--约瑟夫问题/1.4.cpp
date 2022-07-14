#include<iostream>
#include<vector>
using namespace std;

// 约瑟夫问题
//循环链表
typedef struct node{
    int data;
    node *next;
}*Linklist;

// 初始化循环链表
void init_Linklist(Linklist &L){
   L=new node;
   L->next=L;
}

// 判断循环链表是否为空
bool is_empty(Linklist L){
    return L->next==L;
}

// 在循环链表L的第i个位置插入元素e(i=1时，插入在链表头)
void insert_Linklist(Linklist &L, int i, int e){
    Linklist p=L;
    Linklist s=new node;
    s->data=e;
    s->next=NULL;
    if(i==1){
        L->data=e;
    }else{
        for(int j=1;j<i-1;j++){
            p=p->next;  
        }
        s->next=p->next;
        p->next=s;
    }
}


int main(){
    Linklist L;
    init_Linklist(L);
    int num,interval;
    int kill=0;
    cin>>num>>interval;
    for(int i=1;i<=num;i++){
        insert_Linklist(L,i,i);
    }
    Linklist p=L;
    while (p->next!=L)
    {
        p=p->next;
    }
    cout<<"不幸遇难的人为：";
    while(p->next!=p){
        if(kill==num-interval){
            cout<<"存活的人为：";
           while(interval--){
               cout<<p->data<<" ";
                p=p->next;
           }
           return 0;
        }
        for(int i=1;i<=interval;i++){
            p=p->next;
        }
        cout<<p->next->data<<" ";
        kill++;
        p->next=p->next->next;
    }
}
