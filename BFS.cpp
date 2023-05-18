#include<bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1000;
int adj_mat[100][100]={0};
int dist[MAX_NODES]={-1};
string q[MAX_NODES];
int previous[100]={-1};
string target;
int top=-1;
int last=-1;

void push(string *q,string *name,int index)
{
    last++;
    if(top==-1)top++;
    q[last]=name[index];
}

void pop(string *q)
{
    if(q[top]!=target)cout<<q[top]<<" ";
    top++;
    if(top>last){
        top=-1;
        last=-1;
    }
}

void graph(string *name,string v1,string v2,int n)
{
    int i,j;
    for(i=0;i<n;i++){
        if(name[i]==v1)break;
    }
    for(j=0;j<n;j++){
        if(name[j]==v2)break;
    }
    adj_mat[i][j]=1;
    adj_mat[j][i]=1;
}

void bfs(string *name,string start,int n)
{
    int i,j,k;
    int visited[n]={0};
    for(i=0;i<n;i++){
        if(name[i]==start)break;
    }
    push(q,name,i);
    visited[i]=1;
    dist[i]=0;
    previous[i]=-1;
    while(top!=-1){
        pop(q);
        for(k=0;k<n;k++){
            if(adj_mat[i][k]==1 && visited[k]==0){
                push(q,name,k);
                visited[k]=1;
                dist[k]=dist[i]+1;
                previous[k]=i;
            }
        }
        for(i=0;i<n;i++)
            if(name[i]==q[top])break;
    }
}

void shortest_path(int i,string *name)
{
    if(previous[i]!=-1)shortest_path(previous[i],name);
    cout<<name[i]<<" ";
}


int main() {
    int i,j,n,x;
    string v1,v2,ch;
    cout<<"Enter number of countries: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>x;
    string name[n];
    cout<<"Enter name of countries: "<<endl;
    for(i=0;i<n;i++)
        cin>>name[i];

    cout<<"Enter the connections: "<<endl;
    for(i=0;i<x;i++){
        cin>>v1>>v2;
        graph(name,v1,v2,n);
    }

    cout<<"Enter name of country to find connections with: "<<endl;
    cin>>target;
    bfs(name,target,n);
    cout<<endl;

    cout<<"Enter country name to find shortest path from "<<target<<": ";
    cin>>ch;
    for(i=0;i<n;i++)
        if(name[i]==ch)break;
    shortest_path(i,name);
    cout<<endl;

    cout<<"Enter country name to find shortest distance from: ";
    cin>>target;
    for(i=0;i<n;i++){
        if(name[i]==target)break;
    }
    cout<<"Shortest distance from "<<target<<" to "<<ch<<": "<<dist[i]<<endl;

    return 0;
}
