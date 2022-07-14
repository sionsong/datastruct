#include<iostream>
#include<vector>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
 
//通过Dijkstra和Floyd算法，实现图的最短路径；
//邻接矩阵法
typedef struct Mgraph{
    int Vex[100];//顶点数组
    int Edge[100][100];//边数组
    int vexnum,edgenum;//图的顶点数和边数
}Mgraph;
 
 
 
//dijkstra算法
void dijkstra(Mgraph G){
    int s[G.vexnum]={0};  //记录每个顶点是否被访问过   
    int dist[G.vexnum];   //记录每个顶点到起点的距离
    int path[G.vexnum];   //记录路径
    for(int i=0;i<G.vexnum;i++){  
        dist[i]=G.Edge[0][i];  //初始化
        path[i]=0;
    }
    dist[0]=0;  //起点
    for(int i=1;i<G.vexnum;i++){
        int min=inf;
        int k;
        for(int j=0;j<G.vexnum;j++){ //找到最小的边
            if(dist[j]<min&&dist[j]!=inf&&s[j]==0){ 
                min=dist[j]; 
                k=j;   //记录最小边的下标
            }
        }
        s[k]=1;
        for(int j=0;j<G.vexnum;j++){ //更新dist
            if(G.Edge[k][j]<inf&&dist[j]>dist[k]+G.Edge[k][j]){  
                dist[j]=dist[k]+G.Edge[k][j];  
                path[j]=k;  //记录路径
            }
        }
    }
    for(int i=0;i<G.vexnum;i++){
        cout<<"起点到"<<i<<"的距离为："<<dist[i]<<endl;
        cout<<"路径为：";
        int k=i;
        while(k!=0){
            cout<<k<<"<-";
            k=path[k];
        }
        cout<<"0"<<endl;
    }
}
 
//floyd算法 可以用于求任意两点之间的最短路径

void printpath(int path[][100],int u,int v){
    if(path[u][v]==-1){
        cout<<v<<" ";
        return;
    }
    else{
        int mid=path[u][v];
        printpath(path,u,mid);
        printpath(path,mid,v);
    }
}

void floyd(Mgraph G){
    int dist[G.vexnum][100];
    int path[G.vexnum][100];
    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            dist[i][j]=G.Edge[i][j];  //初始化
            path[i][j]=-1;  //初始化
        }
    }

    for(int k=0;k<G.vexnum;k++){
        for(int i=0;i<G.vexnum;i++){
            for(int j=0;j<G.vexnum;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){  //更新dist
                    dist[i][j]=dist[i][k]+dist[k][j];  //更新路径
                    path[i][j]=k;  //更新路径
                }
            }
        }
    }

    for(int i=0;i<G.vexnum;i++){
        for(int j=0;j<G.vexnum;j++){
            cout<<"从"<<i<<"到"<<j;
            if (dist[i][j]==inf)
            cout<<"  无路径"<<endl;
            else{cout<<"的最短路径为："<<i<<" ";
            printpath(path,i,j);
            cout<<endl;}
        }
    }
}


 
int main(){
    Mgraph G;
    G.vexnum=6;
    G.edgenum=9;
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            G.Edge[i][j] = inf;
        }
        
    }
    G.Edge[0][1]=1;
    G.Edge[0][2]=12;
    G.Edge[1][3]=3;
    G.Edge[1][2]=9;
    G.Edge[3][2]=4;
    G.Edge[2][4]=5;
    G.Edge[3][4]=13;
    G.Edge[3][5]=15;
    G.Edge[4][5]=4;
    cout<<"===========================================================Dijkstra算法==========================================================="<<endl;
    dijkstra(G);
    cout<<"===========================================================Floyd算法==========================================================="<<endl;
    floyd(G);
    return 0;
}