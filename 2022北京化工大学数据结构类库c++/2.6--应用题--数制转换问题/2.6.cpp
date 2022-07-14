#include<iostream>
#include<vector>
using namespace std;
//数制转换

void Convert(int n, int base)
{
    vector<int> v;
    while(n > 0)
    {
        v.push_back(n % base);
        n /= base;
    }
    for(int i = v.size() - 1; i >= 0; i--)
        cout << v[i];
}

int main(){
    int n, base;
    cin >> n >> base;
    Convert(n, base);
    return 0;
}