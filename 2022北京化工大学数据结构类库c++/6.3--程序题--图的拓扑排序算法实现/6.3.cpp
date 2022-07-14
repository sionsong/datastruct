#include<iostream>
#include<vector>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;

//图的拓扑排序算法

//邻接矩阵法
typedef struct Mgraph{
    int Vex[100];//顶点数组
    int Edge[100][100];//边数组
    int vexnum,edgenum;//图的顶点数和边数
}Mgraph;

void TopologicalSort(Mgraph G){
    //拓扑排序
    int indegree[G.vexnum];
    for(int i=0;i<G.vexnum;i++){
        indegree[i]=0;
    }

    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            if(G.Edge[i][j]!=inf){
                indegree[j]++;//计算每个顶点的入度
            }
        }
    }
    vector<int> topo;
    for(int i=0;i<G.vexnum;i++){
        if(indegree[i]==0){
            topo.push_back(i); //把入度为0的顶点加入到拓扑序列中
        }
    }
    for(int i=0;i<topo.size();i++){
        for(int j=0;j<G.vexnum;j++){
            if(G.Edge[topo[i]][j]!=inf){
                indegree[j]--;
                if(indegree[j]==0){
                    topo.push_back(j);//把入度为0的顶点加入到拓扑序列中
                }
            }
        }
    }
    for(int i=0;i<topo.size();i++){
        cout<<topo[i]<<" "; //输出拓扑序列
    }
    cout<<endl;

}

int main(){
    Mgraph G;
    G.vexnum=6;
    G.edgenum=8;
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            G.Edge[i][j] = inf;
        }
    }
    G.Edge[3][2]=1;
    G.Edge[4][2]=1;
    G.Edge[2][1]=1;
    G.Edge[2][5]=1;
    TopologicalSort(G);
    return 0;
}