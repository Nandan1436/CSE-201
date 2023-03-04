#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int *num,int n)
{
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=num[i];
        j=i-1;
        while(j>=0 && num[j]>temp){
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=temp;
    }
}

int main()
{
    clock_t start,end;
    start=clock();

    int num[10]={3,5,10,2,1,6,7,8,9,9};
    insertionsort(num,10);
    for(int i=0;i<10;i++)
        printf("%d ",num[i]);
    end=clock();
    printf("\n%lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
