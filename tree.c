#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node*left;
    int data;
    struct Node *right;
};

struct Node *create()
{
    int data;
    struct Node *r;
    printf("\n Enter data=");
    scanf("%d",&data);
    if (data==-1)
    {
        return 0;
    }
    r=(struct Node*)malloc(sizeof(struct Node));
    r->data=data;
    printf("\nEnter left child %d",data);
    r->left =create();
    printf("\nEnter right child %d",data);
    r->right=create();
    return r;
}
void inorder(struct Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
void search(struct Node *root, int key)
{
    struct Node *temp=root;
    printf(" visited node ");
    while(temp!=NULL)
    {
        if(temp ->data==key)
        {
            printf("\nkey is found\n");
            printf("%d\n",temp->data);
            return;
        }
        else if(key<temp->data)
        {
            temp=temp->left;
            printf("%d\n",temp->data);
        }
        else
        {
            temp=temp->right;
            printf("%d\n",temp->data);
        }
        printf("%d\n",temp->data);
    }
}
void main()
{
    struct Node *root;
    root=NULL;
    root = create();
    inorder(root);
    search(root,8);
}
