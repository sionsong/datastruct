#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//简单选择排序和堆排序
void selectSort(vector<int> &a){
    int i,j,min;
    for (i = 1; i < a.size(); i++)
    {
        min = i;
        for (j = i + 1; j < a.size(); j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}

void print(vector<int> a){
    for (int i = 1; i <a.size() ; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
}

//堆排序
void creatheap(vector<int> &a,int i,int n){ //整理以i为根节点，含节点数为n的树
    int j,k;
    k = a[i]; //保存根节点，相当于tmp，下面的向上推
    for (j = 2*i; j <= n; j *= 2)  //每次从变化节点向下进行操作
    {
        if (j < n && a[j] < a[j + 1])   
        {
            j++;  //找到最大的孩子
        }
        if (k >= a[j])
        {
            break;      //如果最大的孩子没有父亲大，就不交换
        }
        a[i] = a[j];    //最大的孩子比父亲大,进行交换
        i = j; //记录交换的位置
    }
    a[i] = k;   //把原来的父亲放到合适的位置
}

void heapSort(vector<int> &a){
    int i,n;
    n = a.size() - 1; //从1出发
    for (i = n / 2; i >= 1; i--)   //每一个非树叶节点都遍历到
    {
        creatheap(a, i, n); //整理以i为根节点的树
    }
    for (i = n; i >= 2; i--)  //每个都要遍历
    {
        swap(a[1], a[i]);   //将堆顶元素与最后一个元素交换
        creatheap(a, 1, i - 1); //每次将最大的元素放到最后，所以只要自顶而下就行了
    }
}

int main(){
    vector<int> a;
    a.push_back(0);
    cout<<"输入一串数据，以-1结束:"<<endl;
    while(1)
    {int k;
    cin>>k;
    if (k==-1)
    {
        break;
    }
    a.push_back(k);}
    vector<int> b=a;
    selectSort(b);
    cout<<"简单选择排序后的数据为："<<endl;
    print(b);
    vector<int> c=a;
    heapSort(c);
    cout<<"堆排序后的数据为："<<endl;
    print(c);

}