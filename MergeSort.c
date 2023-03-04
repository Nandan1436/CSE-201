#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void MergeSort(int *a,int *b,int lb,int hb)
{
    if(lb<hb)
    {
        int mid=(lb+hb)/2;
        MergeSort(a,b,lb,mid);
        MergeSort(a,b,mid+1,hb);
        Merge(a,b,lb,mid+1,hb);
    }
}

void Merge(int *a,int *b,int lpos,int rpos,int rend)
{
    int tempos=lpos;
    int lend=rpos-1;
    int element=rend-lpos+1; //how many elements are in the subarray
    while(lpos<=lend && rpos<=rend)
    {
        if(a[lpos]<=a[rpos])
        {
            b[tempos]=a[lpos];
            lpos++;
        }
        else
        {
            b[tempos]=a[rpos];
            rpos++;
        }
        tempos++;
    }
    while(lpos<=lend)
    {
        b[tempos]=a[lpos];
        tempos++;
        lpos++;
    }
    while(rpos<=rend)
    {
        b[tempos]=a[rpos];
        tempos++;
        rpos++;
    }
    for(int i=0;i<element;i++)
    {
        a[rend]=b[rend];
        rend--;
    }

}

int main()
{
    clock_t start,end;
    start=clock();

    int num[]={10,9,7,1,4,5,3,70};
    int n=sizeof(num)/sizeof(num[0]);
    int i,b[n];
    MergeSort(num,b,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",num[i]);
    end=clock();
    printf("\n%lf\n",(double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
