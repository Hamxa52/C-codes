#include<stdio.h>
#include<stdlib.h>
#define max 5
#define VISITED -1
#define UNVISITED 0
struct graphnode
{
    int data;
    struct graphnode*next;
};
struct graphnode*arr[max];
int vertex_list[max]={1,2,3,4,5};
int visited_list[max];
int q[max];
int front=-1;
int rear=-1;

void addq(int data)
{
    if(rear>=max-1)
    {
        printf("\nQueue is full. \n");
        return;
    }
    rear++;
    q[rear]=data;
    if(front==-1)
    {
        front++;
    }
}

void delq()
{
    if(front==-1)
    {
        printf("\n Queue is empty.\n");
    return;
    }
    q[front]=0;
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}
struct graphnode*createlist(int vertex)
{
    struct graphnode*r;
    int data;
    printf("vertex %d connected to: ",vertex);
    scanf("%d",&data);
    if(data==-1)
    {
        return NULL;
    }
    r=(struct graphnode*)malloc(sizeof(struct graphnode));
    r->data=data;
    r->next=createlist(vertex);
    return r;
}

int find_index(int cwv)
{
    int i;
    for(i=0;i<max;i++)
    {
        if (cwv==vertex_list[i])
        {
            return i;
        }
        
    }
}

void bfs(int cwv) //cwv current working vertex
{
    // Rule 1
    int vli=0; //visited vertex list
    visited_list[0]=cwv; //vist and worked as visited
    printf("\n%d",cwv); //display current vertex
    addq(cwv);
    //int pai=find_index(cwv); //0
    struct graphnode *adjecent=arr[find_index(cwv)]; //set pointer to starting address of list 
    //Rule 2
    int i;
    int flag;
    while(front!=-1)
    {
        while(adjecent!=NULL)
        {
            for(i=0;i<max;i++)
            {
                if(adjecent->data==visited_list[i])
                {
                    flag = VISITED;
                    break;
                }
            }
            if (flag==UNVISITED)
            {
                vli;
                visited_list[vli]=adjecent->data;
                printf("\t%d",adjecent->data);
                addq(adjecent->data);
                adjecent=adjecent->next;
            }
            else
            {
                adjecent=adjecent->next;
            }
        }
        delq();
        cwv=q[front];
        adjecent=arr[find_index(cwv)];
    }
}

int main()
{
    int i;
    for(i=0;i<max;i++)
    {
        arr[i]= createlist(vertex_list[i]);
    }
    
    for(i=0;i<max;i++)
    {
        printf("\nAdjecent of %d:\n",vertex_list[i]);
        struct graphnode*temp=arr[i];
    
        while(temp!=NULL)
        {
            printf("\t%d",temp->data);
            temp=temp->next;
        }
    }
    bfs(1);
    return 0;
}
