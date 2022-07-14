#include<iostream>
#include<vector>
using namespace std;
//图的遍历算法 
 
//图的存储结构——邻接矩阵法
typedef struct Mgraph{
    int Vex[100];//顶点数组
    int Edge[100][100];//边数组
    int vexnum,edgenum;//图的顶点数和边数
}Mgraph;
 
//图的遍历算法——深度优先搜索
void DFS(Mgraph G,int v,int visited[]){
    visited[v]=1;
    cout<<v<<" ";
    for(int i=0;i<G.vexnum;i++){
        if(G.Edge[v][i]==1&&visited[i]==0){
            DFS(G,i,visited);
        }
    }
}
 
void DFSsearch(Mgraph G){
    int visited[G.vexnum];
    for(int i=0;i<G.vexnum;i++){
        visited[i]=0;
    }
    for(int i=0;i<G.vexnum;i++){
        if(visited[i]==0){
            DFS(G,i,visited);
        }
    }
}
 
//图的遍历算法——广度优先搜索BFS
void BFS(Mgraph G,int v,int visited[]){
    vector<int> queue;
    visited[v]=1;
    cout<<v<<" ";
    queue.push_back(v);
    while(!queue.empty()){
        v=queue.front();
        queue.erase(queue.begin());
        for(int i=0;i<G.vexnum;i++){
            if(G.Edge[v][i]==1&&visited[i]==0){
                visited[i]=1;
                cout<<i<<" ";
                queue.push_back(i);
            }                     
        }
    }
}
 
void BFSsearch(Mgraph G){
    int visited[G.vexnum];
    for(int i=0;i<G.vexnum;i++){
        visited[i]=0;
    }
    for(int i=0;i<G.vexnum;i++){
        if(visited[i]==0){
            BFS(G,i,visited);
        }
    }
}
 
 
int main(){
    Mgraph G;
    G.vexnum=5;
    G.edgenum=8;
    for(int i=0;i<G.vexnum;i++){
        G.Vex[i]=i;
    }
    G.Edge[0][1]=1;
    G.Edge[0][2]=1;
    G.Edge[1][3]=1;
    G.Edge[1][4]=1;
    G.Edge[2][1]=1;
    G.Edge[2][3]=1;
    G.Edge[3][4]=1;
    G.Edge[4][2]=1;
    cout<<"深度优先搜索DFS：";
    DFSsearch(G);
    cout<<endl;
    cout<<"广度优先搜索BFS：";
    BFSsearch(G);
    cout<<endl;
    return 0;
}