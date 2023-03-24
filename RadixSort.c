#include <stdio.h>
#include <stdlib.h>

int MaxValue(int num[],int n)
{
    int i,max=0;
    for(i=0;i<n;i++){
        if(num[i]>max)max=num[i];
    }
    return max;
}

void RadixSort(int num[],int n)
{
    int max=MaxValue(num,n);
    int pos;
    for(pos=1;max/pos>0;pos=10*pos){
        CountSort(num,n,pos);
    }
}

void CountSort(int num[],int n,int pos)
{
    int count[10]={0},newnum[n];
    int i;
    for(i=0;i<n;i++){
        count[(num[i]/pos)%10]++;
    }
    for(i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--){
        newnum[count[(num[i]/pos)%10]-1]=num[i];
        count[(num[i]/pos)%10]--;
    }
    for(i=0;i<n;i++){
        num[i]=newnum[i];
    }

}

int main()
{
    int num[11]={9,33,46,12,99,450,233,1900,1000,1,34444};
    int n=11,i;
    RadixSort(num,n);
    for(i=0;i<n;i++)
        printf("%d ",num[i]);

    return 0;
}
