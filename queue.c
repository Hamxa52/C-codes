#include<stdio.h>
#include<malloc.h>
struct Queue
{
    int data;
    struct Queue*link;
};
void display(struct Queue **pfront, struct Queue **prear)
{
    struct Queue*temp = *pfront;
    int i=1;
    while(temp!=*pfront || i==1)
    {
        i++;
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    
}
void addQ(struct Queue **pfront,struct Queue **prear,int data)
{
    struct Queue *r;
    r=(struct Queue*)malloc(sizeof(struct Queue));
    r->data=data;
    r->link=NULL;
    if(*pfront==NULL&&*prear==NULL)
    {
        *pfront=r;
        *prear=r;
    }
    else
    {
        r->link= *pfront;
        (*prear)->link=r;
        *prear=r;
    }
     
}
void delQ(struct Queue **pfront,struct Queue **prear)
{
    if(*pfront==NULL&&*prear==NULL)
    {
        printf("Queue is empty");
        return;
        
    }
    struct Queue *temp=*pfront;
    *pfront=(*pfront)->link;
    printf("deleted data =%d\n",(temp)->data);
    (*prear)->link=*pfront;
    if(*pfront==NULL)
    {
        *prear=NULL;
    }
    free(temp);
}
void main ()
{
    struct Queue *front;
    struct Queue *rear;
    front=NULL;
    rear=NULL;
    addQ(&front,&rear,10);
    addQ(&front,&rear,20);
    addQ(&front,&rear,30);
    addQ(&front,&rear,40);
    display(&front,&rear);
    delQ(&front,&rear);
    delQ(&front,&rear);
    display(&front,&rear);
    
}