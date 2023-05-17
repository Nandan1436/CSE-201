#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_NODES = 1000;
int adj_mat[100][100]={0};
int top=-1;
int last=-1;

void push(int *q,int *num,int index)
{
    last++;
    if(top==-1)top++;
    q[last]=num[index];
}

void pop(int *q)
{
    cout<<q[top]<<endl;
    top++;
    if(top>last){
        top=-1;
        last=-1;
    }
}

void graph(int v1,int v2)
{
    adj_mat[v1][v2]=1;
    adj_mat[v2][v1]=1;
}

void bfs(int *num,int start,int n)
{
    int i,j,k;
    int q[MAX_NODES];
    int visited[5]={0};
    for(i=0;i<5;i++){
        if(num[i]==start)break;
    }
    push(q,num,i);
    visited[i]=1;
    while(top!=-1){
        pop(q);
        for(k=0;k<5;k++){
            if(adj_mat[i][k]==1 && visited[k]==0){
                push(q,num,k);
                visited[k]=1;
            }
        }
        for(i=0;i<5;i++)
            if(num[i]==q[top])break;

    }

}


int main() {
    int i,j,n,x,v1,v2;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>x;
    int num[n];
    for(i=0;i<n;i++)
        cin>>num[i];
    for(i=0;i<x;i++){
        cin>>v1>>v2;
        graph(v1,v2);
    }
    bfs(num,1,n);


    return 0;
}
