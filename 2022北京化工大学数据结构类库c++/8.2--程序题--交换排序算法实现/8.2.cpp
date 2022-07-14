#include<iostream>
#include<vector>
using namespace std;
//实现交换排序算法中的起泡排序和快速排序
//冒泡排序
void bubbleSort(vector<int>& v)
{
    int i, j;
    for (i = 0; i < v.size() - 1; i++)
    {
        for (j = 0; j < v.size() - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

//快速排序
void partition(vector<int>& v,int low,int high){
    int i = low;
    int j = high;
    int key = v[low];
    while(i < j){
        while(i < j && v[j] >= key)
            j--;
        v[i] = v[j];
        while(i < j && v[i] <= key)
            i++;
        v[j] = v[i];
    }
    v[i] = key;
    if(low < i - 1)
        partition(v,low,i - 1);
    if(high > i + 1)
        partition(v,i + 1,high);
}

void print(vector<int> a){
    for (int i = 1; i <a.size() ; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
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
    bubbleSort(a);
    cout<<"冒泡排序后："<<endl;
    print(a);
    cout<<"快速排序后："<<endl;
    partition(a,0,a.size()-1);
    print(a);
}