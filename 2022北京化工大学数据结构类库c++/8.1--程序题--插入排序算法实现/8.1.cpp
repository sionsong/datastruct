#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void print(vector<int> a){
    for (int i = 1; i <a.size() ; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
}
//插入排序
void insertsort(vector<int> &a){
    int j;
    for (int i = 2; i < a.size(); i++)
    {
        a[0]=a[i];
        if(a[i]>=a[i-1]){
            continue;
       }
       else{
           for(j=i-1;a[j]>=a[0]&&i>=1;j--)
           a[j+1]=a[j];           
       }
       a[j+1]=a[0];
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
    insertsort(a);
    print(a);
}