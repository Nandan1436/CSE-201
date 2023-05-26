#include<bits/stdc++.h>

using namespace std;

int adj_mat[100][100],color[100],f[100];
int t;

void graph(int *num,int n,int v1,int v2)
{
    int i,j;
    for(i=0;i<n;i++)
        if(num[i]==v1)break;
    for(j=0;j<n;j++)
        if(num[j]==v2)break;
    adj_mat[i][j]=1;
}

int find_max(int n)
{
    int i,x=0;
    for(i=0;i<n;i++){
        if(f[i]>f[x]){
            x=i;
        }
    }
    f[x]=-1;
    return x;
}

void transpose(int n)
{
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            temp=adj_mat[i][j];
            adj_mat[i][j]=adj_mat[j][i];
            adj_mat[j][i]=temp;
        }
    }
}

void dfsVisit(int *num,int n,int i)
{
    color[i]=1;
    cout<<num[i]<<" ";
    t++;
    for(int j=0;j<n;j++){
        if(adj_mat[i][j]==1 && color[j]==0)
            dfsVisit(num,n,j);
    }
    color[i]=2;
    t++;
    f[i]=t;
}

void dfs(int *num,int n,int i)
{
    for(int j=0;j<n;j++){
        color[j]=0;
        f[j]=1000000;
    }
    t=0;
    dfsVisit(num,n,i);
    for(i=0;i<n;i++){
        if(color[i]==0)dfsVisit(num,n,i);
    }
}

void dfs2(int *num,int n,int i)
{
    color[i]=1;
    cout<<num[i]<<" ";
    for(int j=0;j<n;j++){
        if(adj_mat[i][j]==1 && color[j]==0)
            dfs2(num,n,j);
    }
    color[i]=2;
}

void scc(int *num,int n)
{
    transpose(n);
    for(int i=0;i<n;i++)
        color[i]=0;
    for(int i=0;i<n;i++){
        int x=find_max(n);
        if(color[x]==0){
            cout<<"Connected compound of starting from "<<num[x]<<": ";
            dfs2(num,n,x);
            cout<<endl;
        }
    }
}

int main()
{
    int i,j,n,x,v1,v2,source;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>x;
    int num[n];
    cout<<"Enter info of each vertex: "<<endl;
    for(i=0;i<n;i++)
        cin>>num[i];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adj_mat[i][j]=0;
    cout<<"Enter the edges between vertices: "<<endl;
    for(i=0;i<x;i++){
        cin>>v1>>v2;
        graph(num,n,v1,v2);
    }
    cout<<"Enter source: ";
    cin>>source;
    for(i=0;i<n;i++)
        if(num[i]==source)break;
    dfs(num,n,i);
    cout<<endl;
    scc(num,n);

    return 0;
}
