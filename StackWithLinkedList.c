#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *top=NULL;

void push(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=NULL;
    if(top==NULL)top=newnode;
    else {
        newnode->link=top;
        top=newnode;
    }
}

void pop()
{
    if(top==NULL)printf("Stack underflow.\n");
    else if(top->link==NULL){
        struct node *temp;
        temp=top;
        top=NULL;
        free(temp);
    }
    else {
        struct node *temp;
        temp=top;
        top=temp->link;
        free(temp);
    }
}

void peek()
{
    if(top==NULL)printf("Stack is empty.\n");
    else printf("%d\n",top->data);
}

void display()
{
    if(top==NULL)printf("Stack is empty.\n");
    else {
        struct node *temp;
        temp=top;
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
    printf("1.Push  2.Pop  3.Display  4.Peek  5.Quit\n");
    scanf("%d",&choice);
    while(choice!=4){
        if(choice==1){
            int x;
            printf("Enter value: ");
            scanf("%d",&x);
            push(x);
        }
        else if(choice==2)pop();
        else if(choice==3)display();
        else if(choice==4)peek();
        else break;
        printf("1.Push  2.Pop  3.Display  4.Quit\n");
        scanf("%d",&choice);
    }
    return 0;
}
