#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarysearch(int *num,int left,int right,int target)
{
    if(left<=right){
        int mid=(left+right)/2;
        if(num[mid]==target)return 1;
        else if(target>mid)binarysearch(num,mid+1,right,target);
        else binarysearch(num,left,mid-1,target);
    }
    else return -1;
}

int main()
{
    clock_t start,end;

    start=clock();

    int num[100000];
    for(int i=0;i<100000;i++)
        num[i]=i+1;
    int target=100000;
    int t=binarysearch(num,0,99999,target);
    if(t==1)printf("%d found.\n",target);
    else printf("%d not found.\n",target);

    end=clock();
    printf("%lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
