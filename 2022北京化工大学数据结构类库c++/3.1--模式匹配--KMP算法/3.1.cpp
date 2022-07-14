#include<iostream>
#include<string>
using namespace std;

int Index_kmp(string S,string T,int next[]){
    int i=1,j=1;
    while(i<S.size()&&j<T.size()){
        if(j==0||S[i]==T[j]){
            i++;
            j++;
        }else{
            j=next[j];
        }
    }
    if(j>T.size()-1)
        return i-T.size()+1;
    else
        return 0;
}

void get_next(string T,int next[]){
    int i=1,j=0;
    next[1]=0;
    while(i<T.size()-1){
        if(j==0||T[i]==T[j]){
            i++;
            j++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
}

// 测试代码
int main() {
    string S = " BBC ABCDAB ABCDABCDABDE";//由于从1开始，所以第一个字符为空
    string T = " ABCDABD"; //由于从1开始，所以第一个字符为空,真正的T是从第二个字符开始的
    int next[T.size()];
    get_next(T,next);
    int index = Index_kmp(S,T,next);
    cout << "第一个匹配的索引为：" << index << endl;
    return 0;
}