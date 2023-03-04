#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *num,int p,int r)
{
    if(p<r){
        int q=partition(num,p,r);
        quicksort(num,p,q-1);
        quicksort(num,q+1,r);
    }

}

int partition(int *num,int p,int r)
{
    int x=num[r];
    int i=p-1;
    int j,temp;
    for(j=p;j<=r-1;j++){
        if(num[j]<=x){
            i=i+1;
            temp=num[j];
            num[j]=num[i];
            num[i]=temp;
        }
    }
    temp=num[r];
    num[r]=num[i+1];
    num[i+1]=temp;
    return i+1;
}

int main()
{
    clock_t start,end;
    start=clock();

    int num[10]={3,5,10,2,1,6,7,8,9,9};
    quicksort(num,0,9);
    for(int i=0;i<10;i++)
        printf("%d ",num[i]);
    end=clock();
    printf("\n%lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
