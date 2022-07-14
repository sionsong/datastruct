#include<iostream>
#include<vector>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;

//最小生成树 计科A2003 宋佳音

//图的存储结构——邻接矩阵法
typedef struct Mgraph{
    int Vex[100];//顶点数组
    int Edge[100][100];//边数组
    int vexnum,edgenum;//图的顶点数和边数
}Mgraph;

Mgraph G;

//prim算法
void prim(Mgraph G){ //v为起点
    int min,min_index;
    int visited[G.vexnum];
    for(int i=0;i<G.vexnum;i++){//
        visited[i]=0;//初始化
    }
    int v=0; //起点
    visited[v]=1;
    for(int i=0;i<G.vexnum;i++){
        min=G.Edge[v][i];
        min_index=i; 
        for(int j=0;j<G.vexnum;j++){
            if(visited[j]==0&&G.Edge[v][j]<min){  //查找未访问的顶点，并且边的权值小于min
                min=G.Edge[v][j]; //找到最小的边
                min_index=j;    //记录最小边的下标
            }
        }
        if(min!=inf){cout<<"Prim    出发节点："<<v<<" 结束节点"<<min_index<<" 最小权值："<<min<<endl;} //输出最小边
        visited[min_index]=1; //记录已经访问过的顶点
        v=min_index; //更新v
    }
}

typedef struct Edge{
    int start,end,weight;
}Edge;

vector<Edge> ek,edges;

bool cmp(Edge a,Edge b){
    return a.weight<b.weight;
}

//邻接表转三元组表
vector<Edge> turn(Mgraph G){
    Edge e;
    vector<Edge> k;
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            if(G.Edge[i][j]!=inf){
                e.start=i;
                e.end=j;
                e.weight=G.Edge[i][j];
                k.push_back(e);
            }
        }
    }
    return k;
}

void kruskal(vector<Edge> edges){
    int visited[G.vexnum];
    for(int i=0;i<G.vexnum;i++){
        visited[i]=0;
    }
    int v=0;
    visited[v]=1;
    sort(edges.begin(),edges.end(),cmp);
    for(int i=0;i<edges.size();i++){
        if(visited[edges[i].start]==0||visited[edges[i].end]==0){
            cout<<"Kruskal  出发节点："<<edges[i].start<<" 结束节点"<<edges[i].end<<" 最小权值："<<edges[i].weight<<endl;
            visited[edges[i].start]=1;
            visited[edges[i].end]=1;
        }
    }
}


int main(){
    
    G.vexnum=5;
    G.edgenum=8;
    //初始化边权值
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
                G.Edge[i][j] = inf;
        }
    }

    G.Edge[0][1]=1;
    G.Edge[0][2]=2;
    G.Edge[0][3]=3;
    G.Edge[1][2]=1;
    G.Edge[1][3]=2;
    G.Edge[2][3]=1;
    G.Edge[2][4]=2;
    G.Edge[3][4]=1;
    prim(G);
    ek=turn(G);
    kruskal(ek);
    return 0;
}