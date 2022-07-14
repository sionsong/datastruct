#include <iostream>
using namespace std;
//顺序队列
typedef struct Seqlist
{
    int data[1000];
    int front, rear;
} Seqlist;

//队列初始化
void Init(Seqlist &L)
{
    L.front = L.rear = 0;
}

//判断队列是否为空
bool IsEmpty(Seqlist L)
{
    return L.front == L.rear;
}

//入队
void EnQueue(Seqlist &L, int x)
{
    if (L.rear == 1000)
        cout << "队列已满" << endl;
    else
    {
        L.data[L.rear] = x;
        L.rear++;
    }
}

bool DeQueue(Seqlist &L, int &x)
{
    if (L.front == L.rear)
        return false;
    else
    {
        x = L.data[L.front];
        L.front++;
        return true;
    }
}

int main()
{
    Seqlist L;
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
    while (DeQueue(L, x))
        cout << x << " ";
    return 0;
}
