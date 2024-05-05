#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int data;
    struct Queue *link;
    
};
void insertatfront(struct Queue**pfront,struct Queue**prear,int data)
{
    struct Queue*r;
    r=(struct Queue*)malloc(sizeof(struct Queue));
    r->data=data;
    r->link=NULL;
    if(*pfront==NULL && *prear==NULL)
    {
        *pfront=r;
        *prear=r;
    }
    else
    {
        r->link=*pfront;
        *pfront=r;
    }
}
void delatfront(struct Queue**pfront,struct Queue**prear)
{
    if(*pfront==NULL)
    {
        printf("double ended queue is empty");
        return;
    }
    struct Queue *temp=*pfront;
    *pfront=temp->link;
    if (*pfront==NULL)
    {
        *prear=NULL;
    }
    free(temp);
}
void insertatrear(struct Queue**pfront,struct Queue**prear,int data)
{
    struct Queue*r;
    r=(struct Queue*)malloc(sizeof(struct Queue));
    r->data=data;
    r->link=NULL;
    if(*pfront==NULL && *prear==NULL)
    {
        *pfront=r;
        *prear=r;
    }
    else
    {
       (*prear)->link=r;
       *prear=r;
    }
}
void delatrear(struct Queue**pfront,struct Queue**prear)
{
    if(*prear==NULL)
    {
        printf("double ended queue is empty");
        return;
    }
    struct Queue *temp=*pfront;
    *pfront=temp->link;
    if (*prear==NULL)
    {
        *pfront=NULL;
    }
    else
    {
        struct Queue*prevnode;
        while(temp->link=NULL)
        {
            prevnode=temp;
            temp=temp->link;
            *prear=prevnode;
            free(temp);
        }
    }
    free(temp);
}
void main()
{
    struct Queue *front,*rear;
    front=rear=NULL;
    insertatfront(&front,&rear,12);
    // printf(" value of Front is =%d\n ",front->data);
    insertatfront(&front,&rear,13);
    printf(" value of Front is =%d\n ",front->data);
    insertatrear(&front,&rear,10);
    //printf("Value of Rear is =%d\n",rear->data);
    insertatrear(&front,&rear,20);
    printf("Value of Rear is =%d\n",rear->data);
    delatfront(&front,&rear);
    printf("Value is deleted from front=%d\n",front->data);
    delatrear(&front,&rear);
    printf("Value is deleted from rear=%d\n",rear->data);
}