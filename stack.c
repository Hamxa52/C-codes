#include<stdio.h>
#define SIZE 5
struct stack{
    int top;
    unsigned capacity;
    int *
    
}
void push(int *p,int *t,int d,int s)
{
    if(*t>=s)
    {
        printf("Stack is full...\n");
        return;
    }
    *t=*t+1;
    *(p+*t)=d;
}

int pop(int *p,int*t)
{
    int d;
    if(*t==-1)
    {
        printf("Stack is empty...\n");
        return -1;
    }
    d=*(p+*t);
    *t=*t-1;
    return d;
}

int main()
{
    int stack[SIZE];
    int top=-1;
    push(stack,&top,SIZE,10);
    push(stack,&top,SIZE,20);
    push(stack,&top,SIZE,30);
    push(stack,&top,SIZE,40);
    push(stack,&top,SIZE,50);
    printf("%i",stack[top]);
    
}