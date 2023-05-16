#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;

struct node *createNode(int value)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *insert_node(struct node *root,int value)
{
    if(root == NULL){
        return createNode(value);
    }
    if(root->data > value){
        root->left=insert_node(root->left,value);
    }
    else {
        root->right=insert_node(root->right,value);
    }
    return root;
}

void inorder(struct node *root)
{
    if(root==NULL)return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

struct node *findMax(struct node *root)
{
    if(root==NULL){
        printf("Error: Tree is empty.");
        return;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

struct node *findMin(struct node *root)
{
    if(root==NULL){
        printf("Error: Tree is empty.");
        return;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct node *searchNode(struct node *root,int value)
{
    if(root==NULL || root->data==value){
        return root;
    }
    if(value < root->data){
        return searchNode(root->left,value);
    }
    else {
        return searchNode(root->right,value);
    }
}

struct node *findSuccessor(struct node *root,int value)
{
    struct node *newnode = searchNode(root,value);
    if(newnode==NULL){
        return NULL;
    }
    if(newnode->right!=NULL){
        return findMin(newnode->right);
    }
    struct node *successor=NULL;
    struct node *ancestor=root;

    while(ancestor!=newnode){
        if(newnode->data < ancestor->data){
            successor=ancestor;
            ancestor=ancestor->left;
        }
        else if(newnode->data > ancestor->data){
            ancestor=ancestor->right;
        }
        else break;
    }
    return successor;
}

struct node *deleteNode(struct node *root,int value)
{
    if(root==NULL){
        return root;
    }
    if(value < root->data){
        root->left=deleteNode(root->left,value);
    }
    else if(value > root->data){
        root->right=deleteNode(root->right,value);
    }
    else {
        //case 1: No children
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        //case 2: 1 child
        if(root->left==NULL){
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp=root->left;
            free(root);
            return temp;
        }
        //case 3: 2 or more children
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode=findMin(root->right);
        root->data=newnode->data;
        root->right=deleteNode(root->right,newnode->data);
    }
    return root;
}

int main()
{
    int values[]={8,1,4,10,5,12,6,9,3,0,7};
    int newdata,Successor;
    root=NULL;

    for(int i=0;i<10;i++){
        root = insert_node(root,values[i]);
    }

    inorder(root);
    printf("\n");

    printf("Enter new data: ");
    scanf("%d",&newdata);
    root=insert_node(root,newdata);
    inorder(root);
    printf("\n");

    struct node *max=findMax(root);
    printf("Maximum value in the tree: %d\n",max->data);
    struct node *min=findMin(root);
    printf("Minimum value in the tree: %d\n",min->data);

    printf("Enter data to find successor: ");
    scanf("%d",&Successor);
    struct node *successor=findSuccessor(root,Successor);
    if(successor!=NULL){
        printf("The successor of %d is: %d\n",Successor,successor->data);
    }
    else {
        printf("There is no successor of %d\n",Successor);
    }

    inorder(root);
    printf("\n");
    root=deleteNode(root,12);
    inorder(root);
    printf("\n");
    root=deleteNode(root,5);
    inorder(root);
    printf("\n");
    root=deleteNode(root,4);
    inorder(root);

    return 0;
}
