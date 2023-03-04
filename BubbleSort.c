#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t start,end;
    start=clock();

    int num[10];
    int i,j,temp;
    for(i=0;i<10;i++)
        num[i]=i+1;
    for(i=0;i<10-1;i++){
        for(j=0;j<10-1;j++){
            if(num[j]>num[j+1]){
                temp=num[j+1];
                num[j+1]=num[j];
                num[j]=temp;
            }
        }
    }
    for(i=0;i<10;i++)
        printf("%d ",num[i]);

    end=clock();
    printf("\n%lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
