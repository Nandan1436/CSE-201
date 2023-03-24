#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void RadixSort(char ch[][100],int n)
{
    int i,max=strlen(ch[0]),j;
    for(i=0;i<n;i++){
        if(strlen(ch[i])>max)max=strlen(ch[i]);
    }

    for(i=max-1;i>=0;i--){
        CountSort(ch,n,i,max);
    }
}

void CountSort(char ch[][100],int n,int pos,int max)
{
    int count[255]={0},i,j;
    char newch[n][100];
     for(i=0;i<n;i++){
        if(strlen(ch[i])<max){
            for(j=strlen(ch[i]);j<max;j++)
                ch[i][j]='0';
            ch[i][j]=NULL;
        }

    }
    for(i=0;i<n;i++){
        count[ch[i][pos]]++;
    }
    for(i=1;i<255;i++){
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--){
        for(j=0;j<strlen(ch[i]);j++)
            newch[count[(ch[i][pos])]-1][j]=ch[i][j];
        newch[count[(ch[i][pos])]-1][j]=NULL;
        count[(ch[i][pos])]--;
    }

    for(i=0;i<n;i++){
        for(j=0;j<strlen(newch[i]);j++){
            if(newch[i][j]!='0')ch[i][j]=newch[i][j];
            else {
                ch[i][j]=NULL;
                break;
            }
        }
    }

}

int main()
{
    char ch[10][100]={"house","pool","window","powder","in","inglorious","handle","fearsome","philosophy","simple"};
    int n=10;
    RadixSort(ch,n);
    for(int i=0;i<n;i++)
        printf("%s\n",ch[i]);

    return 0;
}
