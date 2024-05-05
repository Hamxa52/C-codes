# include <stdio.h>
# include <stdlib.h>

struct btreenode 
{
  int data;
  struct btreenode *leftchild;
  struct btreenode *rightchild;
};
struct btreenode *insert(struct btreenode *sr, int num)
{
    struct btreenode *r;
    if(sr == NULL)
    {
        r = (struct btreenode *)malloc(sizeof(struct btreenode));
        r -> data = num;
        r-> leftchild = NULL;
        r->rightchild = NULL;
        
        return r;
    }
    else if(num < sr->data)
    {
        sr-> leftchild = insert(sr->leftchild, num);
    }
    else
    {
        sr -> rightchild = insert(sr->rightchild, num);
    }
    
    return sr;
}
void inorder_data(struct btreenode *sr)
{
    
    if(sr != NULL)
    {
        inorder_data(sr->leftchild);
        printf("\t\t%d", sr->data);
        inorder_data(sr->rightchild);
    }
}
void inorder(struct btreenode*sr)
{
    if(sr !=NULL)
    {
        
    inorder(sr->leftchild);
    printf("\n%d\n",sr->data);
    inorder(sr->rightchild);
    }
}

void search(struct btreenode *root,int num,struct btreenode **parent,struct btreenode **x)
{
    struct btreenode*current;
    current=root;
    *parent=NULL;
    while(current!=NULL)
    {
        if(num==current->data)
        {
            *x=current;
            return;
        }
        if(num>current->data)
        {
            *parent=current;
            current=current->rightchild;
        }
        else
        {
            *parent=current;
            current=current->leftchild;
        }
        
    }
    *x=NULL;
}
void delete(struct btreenode *root,int num)
{
    struct btreenode *parent,*x;
    int found;
    char flag;
    if(root==NULL)
    {
        printf("\ntree is empty.");
        return;
    }
    search(root,num,&parent,&x);
    if(x==NULL)
    {
        printf("\n node not exist.");
        return;
    }
    //case1: node that has 0 leftchild
    if(x->leftchild==NULL&&x->rightchild==NULL)
    {
        if(parent->leftchild==x)
        {
            parent->leftchild=NULL;
        }
        else
        {
            parent->rightchild=NULL;
        }
        free(x);
        return;
    }
    //case2a: node that has 1 child on leftside
    if(x->leftchild!=NULL&&x->rightchild==NULL)
    {
      if(parent->leftchild==x)
      {
          parent->leftchild=x->leftchild;
      }
      else
      {
          parent->rightchild=x->leftchild;
      }
    }
    //case2b: node  that has 1 child on rightside
    if(x->leftchild==NULL&&x->rightchild!=NULL)
    {
       if(parent->rightchild==x)
       {
           parent->rightchild=x->rightchild;
       }
       else
       {
            parent->leftchild=x->rightchild;
       }
    }
    //case3: node that has 2 child 
    if(x->leftchild!=NULL&&x->rightchild!=NULL)
    {
        struct btreenode *xsuccesor;
        xsuccesor=x->rightchild;
        parent=x;
        
        while(xsuccesor->leftchild!=NULL)
        {
            parent=xsuccesor;
            xsuccesor=xsuccesor->leftchild;
            flag='l';
        }
        if(flag=='l')
        {
            x->data=xsuccesor->data;
            parent->leftchild=xsuccesor->rightchild;
        }
        else
        {
            x->data=xsuccesor->data;
            parent->rightchild=xsuccesor->rightchild;
        }
        x->data=xsuccesor->data;
        parent->rightchild=xsuccesor->rightchild;
        
    }
}

int main()
{
    struct btreenode *bt;
    int req, num, i=1;
    bt = NULL;
    printf("Enter number of items to be inserted.");
    scanf("%d", &req);
    while(i <= req)
    {
        printf("\nEnter Data");
        scanf("%d", &num);
        bt = insert(bt, num);
        i++;
    }
    printf("\nInorder traversal \n");
    inorder_data(bt);
    printf("\n");
    inorder(bt);
    
    delete(bt, 6);
    printf("\n");
    inorder_data(bt);
    printf("\n");
     inorder(bt);
  //  delete(bt, 4);
    
    return 0;
}
