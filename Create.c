#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *left;
	int data;
	struct Node *right;
};

struct Node * create()
{
	struct Node *r;
	int data;
	printf("\nEnter Data: ");
	scanf("%i",&data);
	if( data == -1)
	{
		return 0;
	}
	r = (struct Node *) malloc(sizeof(struct Node));
	r->data = data;
	printf("\nEnter Left child of %i",data);
	r->left = create();
	printf("\nEnter Right child of %i",data);
	r->right = create();
	
	return r;
}

void inOrder(struct Node *root)
{
	if(root !=NULL)
	{
		inOrder(root->left);
		printf("%d\t",root->data);
		inOrder(root->right);
	}
}

void postOrder(struct Node *root)
{
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("%d\t",root->data);
	}
}

void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d\t",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void search(struct Node *root ,  int key)
{
	struct Node *temp = root;
	printf("\n Visted Nodes are: ");
	
	while(temp != NULL)
	{
		if(temp->data == key)
		{
			printf("Key is Found");
			return ;
		}
		else if(key < temp->data)
		{
			temp = temp->left;
		}
		else
		{	
			temp = temp->right;
		}
	}
	printf("%i Key is not Found",key);	
}

void main()
{
	struct Node *root = NULL;
	root = create();
	//inOrder(root);
	//postOrder(root);
	//preOrder(root);
	search(root , 20);
}