#include<stdio.h>
#include<stdlib.h>
struct btnode
{
   struct btnode*left;
   int data;
   struct btnode*right;
};
void insert(struct btnode**sr,int data)
{
    struct btnode*r,*current,*parent;
    char flag;
    r=(struct btnode*)malloc(sizeof(struct btnode));
    r->left=NULL;
    r->data=data;
    r->right=NULL;
    if(*sr==NULL)
    {
        *sr=r;
    }
    else
    {
        current=*sr;
        parent=NULL;
        while(current!=NULL)
        {
            if(data >current->data)
            {
                parent=current;
                current=current->right;
                flag='r';
            }
            else
            {
                parent=current;
                current=current->left;
                flag='l';
            }
        }
        if(flag == 'r')
        {
            parent->right = r;
                
        }
        else
        {
            parent->left = r;
        }
    }
    
    
}
void inorder(struct btnode*root)
{
    if(root!=NULL)
    {
        
    inorder(root->left);
    printf("\n%d\n",root->data);
    inorder(root->right);
    }
}
void postorder(struct btnode*root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("\n%d\n",root->data);
    }
}
void preorder(struct btnode*root)
{
    if(root!=NULL)
    {
        printf("\n%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    struct btnode*root;
    root=NULL;
    insert(&root,6);
    insert(&root,4);
    insert(&root,10);
    insert(&root,1);
    insert(&root,5);
    insert(&root,8);
    insert(&root,12);
    insert(&root,7);
    insert(&root,9);
    printf("\nInorder\n");
    inorder(root);
    printf("\nPostorder\n");
    postorder(root);
    printf("\nPreorder\n");
    preorder(root);
   // printf("%d",root->data);
//	printf("\n%d",root->right->data);
//	printf("\n%d",root->left->data);
	
    return 0;
}

