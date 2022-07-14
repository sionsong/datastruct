#include<iostream>
#include<vector>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;

//图的关键路径
//邻接矩阵法
typedef struct Mgraph{
    int Vex[100];//顶点数组
    int Edge[100][100];//边数组
    int vexnum,edgenum;//图的顶点数和边数
}Mgraph;

//求图的关键路径
void TopologicalSort(Mgraph G){
}

