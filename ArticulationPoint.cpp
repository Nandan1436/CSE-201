#include <bits/stdc++.h>

using namespace std;

int adj_mat[100][100],d[100],previous[100],color[100],low[100];
int t;
bool articulation[100];

void graph(int *num,int n,int v1,int v2)
{
    int i,j;
    for(i=0;i<n;i++)
        if(num[i]==v1)break;
    for(j=0;j<n;j++)
        if(num[j]==v2)break;
    adj_mat[i][j]=adj_mat[j][i]=1;
}

void dfsVisit(int *num,int n,int currentNode)
{
    color[currentNode]=1;
    low[currentNode]=d[currentNode]=++t;
    int numOfChild=0;
    for(int j=0;j<n;j++){
        if(adj_mat[currentNode][j]){
            if(!color[j]){
                previous[j]=currentNode;
                numOfChild++;
                dfsVisit(num,n,j);

                if(low[currentNode]>low[j])low[currentNode]=low[j];

                if(previous[currentNode]==-1 && numOfChild>1)articulation[currentNode]=true;
                if(previous[currentNode]!=-1 && low[j]>=d[currentNode])articulation[currentNode]=true;
            }
            else if(j!=previous[currentNode]){
                if(low[currentNode]>d[j])low[currentNode]=d[j];
            }
        }
    }
}

void dfs(int *num,int n)
{
    int i;
    for(i=0;i<100;i++){
        color[i]=0;
        previous[i]=-1;
        d[i]=-1;
        low[i]=-1;
        articulation[i]=false;
    }
    t=0;
    for(i=0;i<n;i++){
        if(color[i]==0)
            dfsVisit(num,n,i);
    }
}

int main()
{
    int i,m,n,v1,v2;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    int num[n];
    cout<<"Enter info of each vertex: "<<endl;
    for(i=0;i<n;i++)
        cin>>num[i];
    cout<<"Enter the connections: "<<endl;
    for(i=0;i<m;i++){
        cin>>v1>>v2;
        graph(num,n,v1,v2);
    }
    dfs(num,n);
    cout<<"Articulation points are: ";
    for(i=0;i<n;i++){
        if(articulation[i])cout<<num[i]<<" ";
    }

    return 0;
}
