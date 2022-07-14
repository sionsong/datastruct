#include<iostream>
#include<vector>
using namespace std;

// 顺序表
typedef struct node{
    int data;
    node *next;
}*Linklist;

// 初始化顺序表
void init_Linklist(Linklist &L){
    L = NULL;
}

// 判断顺序表是否为空
bool is_empty(Linklist L){
    return L == NULL;
}

// 在顺序表L的第i个位置插入元素e
void insert_Linklist(Linklist &L, int i, int e){
    Linklist p = L;
    Linklist s = new node;
    s->data = e;
    s->next = NULL;
    if(i == 1){
        s->next = L;
        L = s;
    }else{
        for(int j = 1; j < i-1; j++){
            p = p->next;
        }
        s->next = p->next;
        p->next = s;
    }
}

// 删除顺序表L的第i个位置的元素
void delete_Linklist(Linklist &L, int i){
    Linklist p = L;
    if(i == 1){
        L = L->next;
    }else{
        for(int j = 1; j < i-1; j++){
            p = p->next;
        }
        p->next = p->next->next;
    }
}

// 获取顺序表L的第i个位置的元素
int get_Linklist(Linklist &L, int i){
    Linklist p = L;
    for(int j = 1; j < i; j++){
        p = p->next;
    }
    return p->data;
}

// 打印顺序表L
void print_Linklist(Linklist &L){
    Linklist p = L;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 删除顺序表L
void delete_Linklist(Linklist &L){
    Linklist p = L;
    while(p != NULL){
        L = L->next;
        delete p;
        p = L;
    }
}

int main(){
    Linklist L;
    init_Linklist(L);
    insert_Linklist(L, 1, 1); // 1
    insert_Linklist(L, 2, 2); // 1 2
    insert_Linklist(L, 3, 3); // 1 2 3
    insert_Linklist(L, 4, 4); // 1 2 3 4
    insert_Linklist(L, 5, 5); // 1 2 3 4 5
    print_Linklist(L);
    delete_Linklist(L);
    return 0;
}

