#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *head=NULL,*tail=NULL;

void enqueue(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=NULL;
    if(head==NULL && tail==NULL){
        head=newnode;
        tail=newnode;
    }
    else {
        tail->link=newnode;
        tail=newnode;
    }
}

void dequeue()
{
    if(head==NULL && tail==NULL)printf("Queue is empty.\n");
    else if(head->link==NULL && tail->link==NULL){
        struct node *temp;
        temp=head;
        head=NULL;
        tail=NULL;
        free(temp);
    }
    else {
        struct node *temp;
        temp=head;
        head=temp->link;
        free(temp);
    }
}

void peek()
{
    if(head==NULL && tail==NULL)printf("Queue is empty.\n");
    else {
        printf("Front data is: %d\n",head->data);
    }
}

void display()
{
    if(head==NULL && tail==NULL)printf("Queue is empty.\n");
    else {
        struct node *temp;
        temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    printf("1.Enqueue  2.Dequeue  3.Peek  4.Display  5.Exit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    while(choice!=5){
        if(choice==1){
            int x;
            printf("Enter value: ");
            scanf("%d",&x);
            enqueue(x);
        }
        else if(choice==2)dequeue();
        else if(choice==3)peek();
        else if(choice==4)display();
        else break;
        printf("1.Enqueue  2.Dequeue  3.Peek  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
    }
    return 0;
}
