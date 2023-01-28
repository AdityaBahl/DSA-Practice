#include <stdio.h>
#include <stdlib.h>
typedef struct nodes
{
    int num;
    struct nodes *next;
}node;
node *insert(node*);
void dlt(node*);
void display(node*);
int main()
{
    node *left = NULL;
    int ch;
    while(1)
    {
        printf("1.) Insert\n2.) Delete alternate\n3.) Display\n4.) Exit\n(Error if any other value is typed)\n");
        scanf("%d",&ch);
        switch(ch)
            {
            case 1:
                left=insert(left);
                break;
            case 2:
                dlt(left);
                break;
            case 3:
                display(left);
                break;
            case 4:
                return 0;
            default:
                printf("Wrong Value has been Input\n");
                break;
            }
    }
}
node *insert(node* left)
{
    int data;
    node *p=NULL;
    printf("Enter The Value\n");
    scanf("%d",&data);
    p=(node*)malloc(sizeof(node));
    if(p==NULL)
    {
        printf("Memory not allocated!\n");
        return p;
    }
    else
    {
        p->num=data;
        p->next=left;
        left=p;
    }
    return left;
}
void dlt(node* left)
{
    int n;
    printf("Enter The key to be deleted:\n");
    scanf("%d",&n);
    node *t=left;
    while(n!=(t->num)&&t->next!=NULL)
    {
        t=t->next;
    }
    if(n!=(t->num)&&t->next==NULL)
    {
        printf("Sorry, key not found");
    }
    else{
    if(t==(left))
    {
        left=left->next;
    }
        free(t);
    }
    /*
    node *head = left;
    node *c=left->next;
    while(head!=NULL&&c!=NULL)
    {
        head->next=c->next;
        head=head->next;
        free(c);
        if(head!=NULL)
        {
            c=head->next;//if odd no of elements are present then c becomes NULL(still head is not NULL);
                        // therefore loops continue...and at head->next=c->next(behaves as wild pointer or dangling pointer)
        }
    }
    */
    }
void display(node* left)
{
    if(left==NULL)
    {
        printf("Empty Set\n");
    }
    else{
    printf("The List is\n");
    while(left!=NULL)
    {
        printf("%d\n",left->num);
        left=left->next;
    }
    }
}
