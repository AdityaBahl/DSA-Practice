#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;
Node *start;
void createemptylist(Node *start)
{
    start=NULL;
}
void traverse(Node *start)
{
    Node *p=start;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}


void insertbeg(int item)
{
    Node *ptr,*p=(Node*)malloc(sizeof(Node*));
    p->data=item;
    if(start==NULL)
    {
        p->next=NULL;
    }
    else
    {
        ptr->next=start;
    }
    start=p;
}


void insertend(int item)
{
    Node *loc,*p=(Node*)malloc(sizeof(Node*));
    p->data=item;
    p->next=NULL;
    if(start=NULL)
    {
        start=p;
    }
    else
    {
        loc= start;
    while(loc->next!=NULL)
    {
        loc=loc->next;
    }
    loc->next=p;
    }
}


void insertspl(int item,int loc)
{
    Node *p,*temp;
    int k;
    for(int k=0,temp=start;k<loc;k++)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("Node In the list at less one\n");
            return;
        }
    }
    p=(Node*)malloc(sizeof(Node*));
    p->data=item;
    p->next=loc->next;
    loc->next=p;
}
int main()
{
    Node*start=NULL;
    return 0;
}
