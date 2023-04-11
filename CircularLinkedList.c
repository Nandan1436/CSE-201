#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *tail,*temp;

void createList()
{
    struct node *newnode;
    int choice=1;
    tail=NULL;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(tail==NULL){
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("Would you like to continue?(0/1)");
        scanf("%d",&choice);
    }
}

void insertBeginning()
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(tail==NULL){
        tail=newnode;
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
    }
}

void insertEnd()
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    if(tail==NULL){
        tail=newnode;
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}

void insertPos()
{
    int pos,x,i=1;
    printf("Enter position: ");
    scanf("%d",&pos);
    x=count();
    if(pos<1 || pos>x)printf("Position is invalid.\n");
    else if(pos==1)insertBeginning();
    else {
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        temp=tail->next;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void deleteBeginning()
{
    temp=tail->next;
    if(tail==NULL)printf("List is empty\n");
    else if(temp->next==tail){
        tail=NULL;
        free(temp);
    }
    else{
        tail->next=temp->next;
        free(temp);
    }
}

void deleteEnd()
{
    struct node *previous;
    temp=tail->next;
    if(tail==NULL)printf("List is empty\n");
    else if(tail->next==tail){
        tail=NULL;
        free(temp);
    }
    else{
        while(temp->next!=tail->next){
            previous=temp;
            temp=temp->next;
        }
        previous->next=tail->next;
        tail=previous;
        free(temp);
    }
}

void deletePos()
{
    struct node* nextnode;
    int pos,x,i=1;
    printf("Enter position: ");
    scanf("%d",&pos);
    x=count();
    if(pos==1)deleteBeginning();
    else if(pos==x)deleteEnd();
    else if(pos<1 || pos>x)printf("Position invalid\n");
    else {
        temp=tail->next;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        free(nextnode);
    }
}

int count()
{
    int x=0;
    if(tail==NULL)return x;
    else {
        temp=tail->next;
        while(temp->next!=tail->next){
            x++;
            temp=temp->next;
        }
        x++;
        return x;
    }
}

void displayList()
{
    if(tail==NULL)printf("List is empty.\n");
    else{
        temp=tail->next;
        while(temp->next!=tail->next){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}

int main()
{
    int choice;
    printf("1.Create list  2.Insert beginning  3.Insert position  4.Insert end  5.Delete beginning  6.Delete end  7.Delete position  8.Display list  9.Exit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    while(choice!=9){
        if(choice==1) createList();
        else if(choice==2)insertBeginning();
        else if(choice==3)insertPos();
        else if(choice==4)insertEnd();
        else if(choice==5)deleteBeginning();
        else if(choice==6)deleteEnd();
        else if(choice==7)deletePos();
        else if(choice==8)displayList();
        else break;
        printf("\n");
        printf("1.Create list  2.Insert beginning  3.Insert position  4.Insert end  5.Delete beginning  6.Delete end  7.Delete position  8.Display list  9.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
    }
    return 0;
}
