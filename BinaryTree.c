#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

struct node *create()
{
    int x;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data(-1 for no node): ");
    scanf("%d",&x);
    if(x==-1)return NULL;
    newnode->data = x;
    printf("Enter left child of %d: ",x);
    newnode->left = create();
    printf("Enter right child of %d: ",x);
    newnode->right = create();

    return newnode;

}

void preorder(struct node* root)
{
    struct node *stack[100],*point=root;
    int top=1;
    stack[0]=NULL;
    while(point!=NULL){
        printf("%d ",point->data);
        if(point->right!=NULL){
            stack[top]=point->right;
            top++;
        }
        if(point->left!=NULL)point=point->left;
        else {
            point=stack[--top];
        }
    }
    printf("\n");
}

void inorder(struct node *root)
{
    struct node *stack[100],*point=root;
    int top=-1;

     while (point!= NULL || top!=-1) {
        while(point!=NULL){
            stack[++top]=point;
            point=point->left;
        }
        point=stack[top--];
        printf("%d ",point->data);
        point=point->right;
    }
    printf("\n");
}

void postorder(struct node *root)
{
    int top=-1;
    struct node *stack[100];
    struct node *point=root;
    struct node *lastVisited = NULL;
    while(point!=NULL || top!=-1){
        while(point!=NULL){
            stack[++top]=point;
            point=point->left;
        }
        struct node *peekNode = stack[top];
        if(peekNode->right==NULL || peekNode->right==lastVisited){
            top--;
            printf("%d ",peekNode->data);
            lastVisited=peekNode;
        }
        else point=peekNode->right;
    }

}

int main()
{
    root=create();
    preorder(root);
    inorder(root);
    postorder(root);

    return 0;
}
