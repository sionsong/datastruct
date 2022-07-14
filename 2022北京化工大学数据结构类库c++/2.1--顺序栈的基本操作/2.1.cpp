#include<iostream>
using namespace std;

//顺序栈的实现
typedef struct{
    int data[1000];
    int top;
}SqStack;

//初始化栈
void InitStack(SqStack &S){
    S.top = -1;
}

//判断栈是否为空
bool StackEmpty(SqStack S){
    if(S.top == -1)
        return true;
    else
        return false;
}

//入栈
void Push(SqStack &S, int x){
    if(S.top == 999)
        cout<<"栈满"<<endl;
    else{
        S.top++;
        S.data[S.top] = x;
    }
}

//出栈
void Pop(SqStack &S, int &x){
    if(S.top == -1)
        cout<<"栈空"<<endl;
    else{
        x = S.data[S.top];
        S.top--;
    }
}

//取栈顶元素
void GetTop(SqStack S, int &x){
    if(S.top == -1)
        cout<<"栈空"<<endl;
    else{
        x = S.data[S.top];
    }
}

//遍历栈
void TraverseStack(SqStack S){
    if(S.top == -1)
        cout<<"栈空"<<endl;
    else{
        for(int i = 0; i <= S.top; i++)
            cout<<S.data[i]<<" ";
        cout<<endl;
    }
}

//主函数
int main(){
    int x;
    SqStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    TraverseStack(S);
    Pop(S, x);
    cout<<"出栈元素为："<<x<<endl;
    TraverseStack(S);
    GetTop(S, x);
    cout<<"栈顶元素为："<<x<<endl;
    return 0;
}


