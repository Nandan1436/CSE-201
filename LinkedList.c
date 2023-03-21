#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node*head,*newnode,*tempnode;

void create_list()
{
    int choice;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        tempnode=newnode;
    }
    else {
        tempnode->next=newnode;
        tempnode=newnode;
    }
    printf("Do you want to continue?(0/1)");
    scanf("%d",&choice);
    while(choice){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        tempnode->next=newnode;
        tempnode=newnode;
        printf("Do you want to continue?(0/1)");
        scanf("%d",&choice);
    }
}

void insert_beginning()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}

void insert_end()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    tempnode=head;
    while(tempnode->next!=NULL){
        tempnode=tempnode->next;
    }
    tempnode->next=newnode;

}

void insert_position()
{
    int n=count();
    int i=1,x;
    printf("Enter position: ");
    scanf("%d",&x);
    if(x>n)printf("Invalid position entered\n");
    else {
        tempnode=head;
        while(i<x-1){
            tempnode=tempnode->next;
            i++;
        }
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=tempnode->next;
        tempnode->next=newnode;
    }
}

void delete_beginning()
{
    tempnode=head;
    head=head->next;
    free(tempnode);
}

void delete_end()
{
    struct node *prevnode;
    tempnode=head;
    while(tempnode->next!=NULL){
        prevnode=tempnode;
        tempnode=tempnode->next;
    }
    if(tempnode==head)head=NULL;
    else prevnode->next=NULL;
    free(tempnode);
}

void delete_position()
{
    int x,i=1;
    struct node *nextnode;
    tempnode=head;
    printf("Enter position: ");
    scanf("%d",&x);
    while(i<x-1){
        tempnode=tempnode->next;
        i++;
    }
    nextnode=tempnode->next;
    tempnode->next=nextnode->next;
    free(nextnode);
}

void print_values()
{
    tempnode=head;
    while(tempnode!=0){
        printf("%d ",tempnode->data);
        tempnode=tempnode->next;
    }
}

int count()
{
    int count=0;
    tempnode=head;
    while(tempnode->next!=NULL){
        tempnode=tempnode->next;
        count++;
    }
    return count;
}

int main()
{
    int value,choice;
    head=NULL;
    printf("1.Insert_end  2.Insert_beginning  3.Insert_position  4.Print_list  5.Create_list  6.Delete_beginning  7.Delete_end  8.Delete_position  9.End\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    while(choice!=9){

        if(choice==1){
            insert_end();
        }

        else if(choice==2){
            insert_beginning();
        }

        else if(choice==3){
            insert_position();
        }

        else if(choice==4){
            print_values();
        }
        else if(choice==5){
            create_list();
        }
        else if(choice==6){
            delete_beginning();
        }
        else if(choice==7){
            delete_end();
        }
        else if(choice==8){
            delete_position();
        }

        printf("\n1.Insert_end  2.Insert_beginning  3.Insert_position  4.Print_list  5.Create_list  6.Delete_beginning  7.Delete_end  8.Delete_position  9.End\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
    }
    return 0;
}
