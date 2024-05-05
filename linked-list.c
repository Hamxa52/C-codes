#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//creating node
struct Node
{
	int data;
	struct Node*link;	
};

//	Display Function
void display(struct Node *q)
{
	for(;q!=NULL;)
	{
		printf("%i\n",q->data,q->link);
		q=q->link;
	}
}

//Creating append function
void append(struct Node**q,int d)
{
	struct Node*r,*temp;
	r=(struct Node*)malloc(sizeof(struct Node));
	r->data=d;
	r->link=NULL;
	if(*q==NULL)
	{
		*q=r;
	}
	else
	{
		temp=*q;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=r;
	}
}

//	Adding Node in Begining Function
void addatbegning(struct Node **q, int d)
{
	struct Node *r;
	
	r=(struct Node*)malloc(sizeof(struct Node));
	r->data=d;
	r->link=*q;
	*q=r;
	
}

//Creating new node at the end of link list
void addatend(struct Node **q,int d)
{
	struct Node*r,*temp;
	r=(struct Node*)malloc(sizeof(struct Node));
	r->data=d;
	temp=*q;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=r;
	r->link=NULL;
}

//create node at a specific position
void addatspecific(struct Node **q,int d,int index)
{
	struct Node*r,*temp;
	r=(struct Node*)malloc(sizeof(struct Node));
	
	temp=*q;
	int i=0;
	while(i!= index)
	{
		temp=temp->link;
	i++;
	}
	r->data=d;
	r->link=temp->link;
	temp->link=r;
}

//creating node after a node
void addafternode(struct Node **q,int d)
{
	struct Node*r,*prevNode;
	r=(struct Node*)malloc(sizeof(struct Node));
	r->data=d;
	r->link=prevNode->link;
	prevNode->link=r;
}

//Main Function
void main()
{
	int value,size,i,a=0;
	struct Node *p=NULL;
	char ans;
	
	
	printf("How many Nodes do you want to create= ");
	scanf("%i",&size);
	
	// Loop for calling Node creating function and giving its data part value
	a=1;
	for(i=0; i<size; i++)
	{
		printf("Enter Value for %i Node= ",a);
		scanf("%i",&value);
		append(&p,value);
		a++;
	}
	
	printf("Do you want to add any node in begning?\n");
	printf("Enter \"Y\" for Yes and \"N\" for No = ");
	scanf(" %c",& ans);
	
	// condition for calling add first function for adding a node in the begining
	if(ans=='y' || ans=='Y')
	{
		printf("Enter value of node that you want to add in begining= ");
		scanf("%i",&value);
		size++;
		addatbegning(&p,value);
	}

	//calling display function
	display(p);
	//check for entering node in the end
	printf("Do you want to add any node in end?\n");
	printf("Enter \"Y\" for Yes and \"N\" for No = ");
	scanf(" %c",& ans);
	
	//condition for calling add node at end of all nodes
	if(ans=='y' || ans=='Y')
	{
		printf("Enter value of node that you want to add in end= ");
		scanf("%i",&value);
		size++;
		addatend(&p,value);
	}
	if(ans=='n'|| ans=='N')
	{
	    exit(0);
	}
	display(p);
	printf("How many Nodes do you want to create at end= ");
	scanf("%i",&size);

	// Loop for calling Node creating function and giving its data part value
	a=1;
	for(i=0; i<size; i++)
	{
		printf("Enter Value for %i Node= ",a);
		scanf("%i",&value);
		addatend(&p,value);
		a++;
	}
	display(p);
}
	