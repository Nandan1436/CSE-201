#include <stdio.h>
#include <stdlib.h>

void heapify(int *num,int n,int x)
{
    int left=2*x+1;
    int right=2*x+2;
    int largest=x;
    if(left<n && num[left]>num[largest]){
        largest=left;
    }
    if(right<n && num[right]>num[largest]){
        largest=right;
    }
    if(largest!=x){
        int temp=num[x];
        num[x]=num[largest];
        num[largest]=temp;
        heapify(num,n,largest);
    }
}

void max_heap(int *num,int n)
{
    int x=(n/2)-1;
    for(int i=x;i>=0;i--){
        heapify(num,n,i);
    }
}

int deleteMax(int *num,int *n)
{
    int max=num[0];
    num[0]=num[(*n)-1];
    (*n)--;
    max_heap(num,*n);
    return max;
}

void insert(int *num,int key,int *n)
{
    int i=*n;
    (*n)++;
    num[i]=key;
    while(i>0 && num[(i-1)/2]<num[i]){
        int temp = num[i];
        num[i]=num[(i-1)/2];
        num[(i-1)/2]=temp;
        i=(i-1)/2;
    }
}

void heapSort(int *num,int n)
{
    max_heap(num,n);
    for(int i=n-1;i>0;i--){
        int temp=num[0];
        num[0]=num[i];
        num[i]=temp;
        heapify(num,i,0);
    }
}

void increaseKey(int *num,int i,int key)
{
    if(key<num[i]){
        printf("New key is smaller than current key.\n");
        return;
    }
    num[i]=key;
    while(i>0 && num[(i-1)/2]<num[i]){
        int temp=num[i];
        num[i]=num[(i-1)/2];
        num[(i-1)/2]=temp;
        i=(i-1)/2;
    }
}

void printList(int *num,int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",num[i]);
    }
    printf("\n");
}

int main()
{
    int num[20]={4,1,3,2,16,9,10,14,8,7};
    int n=10;

    max_heap(num,n);
    printList(num,n);

    increaseKey(num,4,20);
    printList(num,n);

    insert(num,15,&n);
    printList(num,n);

    int max=deleteMax(num,&n);
    printf("Maximum value: %d\n",max);

    heapSort(num,n);
    printList(num,n);

    return 0;
}
