#include<iostream>
using namespace std;

// 顺序表
typedef struct sqlist{
    int *data;
    int length;
}sqlist;

// 初始化顺序表
void init_sqlist(sqlist &L){
    L.data = NULL;
    L.length = 0;
}

// 判断顺序表是否为空
bool is_empty(sqlist L){
    return L.data == NULL;
}

// 在顺序表L的第i个位置插入元素e
void insert_sqlist(sqlist &L, int i, int e){
    int *p = new int[L.length+1];
    for(int j = 0; j < L.length; j++){
        p[j] = L.data[j];
    }
    p[i-1] = e;
    L.data = p;
    L.length++;
}

// 删除顺序表L的第i个位置的元素
void delete_sqlist(sqlist &L, int i){
    int *p = new int[L.length-1];
    for(int j = 0; j < i-1; j++){
        p[j] = L.data[j];
    }
    for(int j = i; j < L.length; j++){
        p[j-1] = L.data[j];
    }
    L.data = p;
    L.length--;
}

// 获取顺序表L的第i个位置的元素
int get_sqlist(sqlist &L, int i){
    return L.data[i-1];
}

// 打印顺序表
void print_sqlist(sqlist L){
    for(int i = 0; i < L.length; i++){
        cout << L.data[i] << " ";
    }
    cout << endl;
}


// 测试
int main(){
    sqlist L;
    init_sqlist(L);
    insert_sqlist(L, 1, 1);
    insert_sqlist(L, 2, 2);
    insert_sqlist(L, 3, 3);
    insert_sqlist(L, 4, 4);
    insert_sqlist(L, 5, 5);
    print_sqlist(L);
    delete_sqlist(L, 3);
    print_sqlist(L);
    cout << get_sqlist(L, 3) << endl;
    return 0;
}


