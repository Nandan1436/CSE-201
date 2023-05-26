#include <iostream>

using namespace std;

int adj_mat[100][100];
int color[100],previous[100],d[100],f[100];
int t=0;

void graph(int *num,int v1,int v2,int n)
{
    int i,j;
    for(i=0;i<n;i++)
        if(num[i]==v1)break;
    for(j=0;j<n;j++)
        if(num[j]==v2)break;
    adj_mat[i][j]=1;
    adj_mat[j][i]=1;
}

void dfsVisit(int *num,int n,int i)
{
    color[i]=1;
    t++;
    d[i]=t;
    cout<<num[i]<<" ";
    int j;
    for(j=0;j<n;j++){
        if(adj_mat[i][j]==1 && color[j]==0){
            previous[j]=i;
            dfsVisit(num,n,j);
        }
    }
    color[i]=2;
    t++;
    f[i]=t;
}

void dfs(int *num,int n,int i)
{
    for(int j=0;j<n;j++){
        color[j]=0;
        d[i]=100000000;
        f[i]=10000000;
        previous[i]={-1};
    }
    dfsVisit(num,n,i);
    for(i=0;i<n;i++){
        if(color[i]==0)
            dfsVisit(num,n,i);
    }
}

int main()
{
    int n,x,i,v1,v2,j,temp,source;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>x;
    int num[n];
    cout<<"Enter info of each vertex: "<<endl;
    for(i=0;i<n;i++)
        cin>>num[i];

    cout<<"Enter the connections between vertices: "<<endl;
    for(i=0;i<x;i++){
        cin>>v1>>v2;
        graph(num,v1,v2,n);
    }
    cout<<"Enter source vertex: ";
    cin>>source;
    for(i=0;i<n;i++)
        if(num[i]==source)break;
    dfs(num,n,i);

    return 0;
}
