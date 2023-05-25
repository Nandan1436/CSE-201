#include <bits/stdc++.h>

using namespace std;

int adj_mat[100][100],color[100],f[100],t=0;

void graph(string *course,string v1,string v2,int n)
{
    int i,j;
    for(i=0;i<n;i++)
        if(course[i]==v1)break;
    for(j=0;j<n;j++)
        if(course[j]==v2)break;
    adj_mat[i][j]=1;
}

void topological_sort(string *course1,int n)
{
    int i,j,temp;
    string temp1;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(f[j+1]>f[j]){
                temp1=course1[j];
                course1[j]=course1[j+1];
                course1[j+1]=temp1;

                temp=f[j];
                f[j]=f[j+1];
                f[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
        cout<<course1[i]<<" ";
}

void dfsVisit(string *course,int i,int n)
{
    color[i]=1;
    t++;
    cout<<course[i]<<" ";
    int k;
    for(k=0;k<n;k++){
        if(adj_mat[i][k]==1 && color[k]==0)
            dfsVisit(course,k,n);
    }
    color[i]=2;
    t++;
    f[i]=t;

}

void dfs(string *course,int n)
{
    int i,j;
    color[100]={0};
    f[100]={1000000};
    t=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(adj_mat[i][j]==1 && color[i]==0)
                dfsVisit(course,i,n);
        }
    }
}

int main()
{
    int i,j,x,n;
    string v1,v2;
    cout<<"Enter number of courses: ";
    cin>>n;
    cout<<"Enter number of prerequisites: ";
    cin>>x;

    string course[n],course1[n];
    cout<<"Enter name of courses:"<<endl;
    for(i=0;i<n;i++){
        cin>>course[i];
        course1[i]=course[i];
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adj_mat[i][j]=0;

    cout<<"Enter the prerequisites of the courses: "<<endl;;
    for(i=0;i<x;i++){
        cin>>v1>>v2;
        graph(course,v1,v2,n);
    }
    cout<<"DFS is: ";
    dfs(course,n);
    cout<<endl<<endl;

    cout<<"Topological sort is: ";
    topological_sort(course1,n);
    cout<<endl<<endl;

    cout<<"Finishing times are: "<<endl;
    for(i=0;i<n;i++)
        cout<<course1[i]<<": "<<f[i]<<endl;

    return 0;
}
