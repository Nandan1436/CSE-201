#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *previous;
};
struct node *head,*tail,*temp;

void createList()
{
    head=NULL;
    tail=NULL;
    int choice=1;
    while(choice){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->previous=NULL;
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else {
            tail->next=newnode;
            newnode->previous=tail;
            tail=newnode;
        }
        printf("Do you want to continue?(0/1)");
        scanf("%d",&choice);
    }
}

void insertBeginning()
{
    temp=head;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->previous=NULL;
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else {
        newnode->next=head;
        head->previous=newnode;
        head=newnode;
    }
}

void insertAtPos()
{
    int pos,x;
    printf("Enter position: ");
    scanf("%d",&pos);
    x=count();
    if(pos<1 || pos>x)printf("Invalid position entered.\n");
    else if(pos==1)insertBeginning();
    else {
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d",&newnode->data);
        x=1;
        temp=head;
        while(x<pos-1){
            temp=temp->next;
            x++;
        }
        newnode->previous=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->previous=newnode;
    }
}

void insertAfterPos()
{
    int pos,x;
    printf("Enter position: ");
    scanf("%d",&pos);
    x=count();
    if(pos<1 || pos>x)printf("Invalid position entered.\n");
    else if(pos==x)insertEnd();
    else {
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d",&newnode->data);
        x=1;
        temp=head;
        while(x<pos){
            temp=temp->next;
            x++;
        }
        newnode->previous=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->previous=newnode;
    }
}

void insertEnd()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->previous=NULL;
    tail->next=newnode;
    newnode->previous=tail;
    tail=newnode;
}

void deleteBeginning()
{
    int x=count();
    if(head==NULL)printf("List is empty.\n");
    else if(x==1){
        temp=head;
        head=NULL;
        tail=NULL;
        free(temp);
    }
    else {
        temp=head;
        head=temp->next;
        head->previous=NULL;
        temp->next=NULL;
        free(temp);
    }
}

void deleteAtPos()
{
    int pos,x;
    printf("Enter position: ");
    scanf("%d",&pos);
    x=count();
    if(pos<1 || pos>x)printf("Invalid position entered.\n");
    else if(pos==1)deleteBeginning();
    else if(pos==x)deleteEnd();
    else {
        temp=head;
        int i=1;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        temp->previous->next=temp->next;
        temp->next->previous=temp->previous;
        temp->next=NULL;
        temp->previous=NULL;
        free(temp);
    }
}

void deleteEnd()
{
    int x=count();
    if(tail==NULL)printf("List is empty.\n");
    else if(x==1){
        temp=head;
        head=NULL;
        tail=NULL;
        free(temp);
    }
    else {
        temp=tail;
        tail=temp->previous;
        tail->next=NULL;
        temp->previous=NULL;
        free(temp);
    }
}

int count()
{
    temp=head;
    int x=0;
    if(head==NULL)return x;
    else {
        while(temp!=NULL){
            x++;
            temp=temp->next;
        }
        return x;
    }
}

void displayList()
{
    temp=head;
    if(head==NULL)printf("The list is empty.\n");
    else {
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    printf("1.Create List  2.Insert Beginning  3.Insert End  4.Insert at Position  5.Insert after Position  6.Delete Beginning  7.Delete End  8.Delete at Position  9.Display List  10.Quit\n");
    scanf("%d",&choice);
    while(choice!=10){
        if(choice==1)createList();
        else if(choice==2)insertBeginning();
        else if(choice==3)insertEnd();
        else if(choice==4)insertAtPos();
        else if(choice==5)insertAfterPos();
        else if(choice==6)deleteBeginning();
        else if(choice==7)deleteEnd();
        else if(choice==8)deleteAtPos();
        else if(choice==9)displayList();
        else break;
        printf("1.Create List  2.Insert Beginning  3.Insert End  4.Insert at Position  5.Insert after Position  6.Delete Beginning  7.Delete End  8.Delete at Position  9.Display List  10.Quit\n");
        scanf("%d",&choice);
    }

    return 0;
}
