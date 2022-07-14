#include<iostream>
using namespace std;

//折半查找算法
int binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int key ;
    cin>>key;
    int index = binarySearch(a, n, key);
    if (index == -1)
        cout <<key<<"没有被找到" << endl;
    else
        cout <<key<< "被找到了" << endl;
    return 0;
}