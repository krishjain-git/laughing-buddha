#include<stdio.h>
#include<stdlib.h>

struct node
{
    int expo;
    float coef;
    struct node*link;
};
struct node *insert(struct node*head,float co,int ex)
{
    struct node* temp=NULL;
    struct node* newp=malloc(sizeof(struct node));
    newp->link=NULL;
    newp->coef=co;
    newp->expo=ex;
    if(head==NULL||head->expo<ex)
    {
       newp->link=head;
        head=newp;
    }
    else
    {
        temp=head;
        while(temp->link!=NULL&&temp->link->expo>=ex)
        {
            temp=temp->link;
        }
        newp->link=temp->link;
        temp->link=newp;

    }
    return head;
}
struct node* create(struct node *head)
{
int n,i;
int ex;
float co;
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("ENTER THE COEFICIENT FOR %d TERM ",i+1);
scanf("%f",&co);
printf("ENTER THE EXPONENT FOR %d TERM ",i+1);
scanf("%d",&ex);
head=insert(head,co,ex);
}
return head;
}
void print(struct node* head)
{
if(head==NULL)
{
    printf("NO POLYNOMIAL");
}
else
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("(%.1fx^%d)",temp->coef,temp->expo);
        temp=temp->link;
    if(temp!=NULL)
    {
        printf("+");
    }
    else
    {
        printf("\n");
    }
    }
}
}
struct node* poly_multi(struct node*head1,struct node *head2)
{
    struct node *ptr1=NULL;
    struct node *ptr2=NULL;
    struct node *head3=NULL;
    ptr1=head1;
    ptr2=head2;
    float mul;
    int add;
    while(ptr1!=NULL)
    {
        ptr2=head2;
        while(ptr2!=NULL)
        {
         mul=ptr1->coef*ptr2->coef;
         add=ptr1->expo+ptr2->expo;
         head3=insert(head3,mul,add);
         ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
    }
    return head3;
}
int main()
{
struct node*head1=NULL;
struct node*head2=NULL;
printf("ENTER THE NUMBER OF TERM IN FIRST POLY");
head1=create(head1);
printf("ENTER THE NUMBER OF TERM IN SECOND POLY");
head2=create(head2);
print(head1);
print(head2);
struct node *multi= poly_multi(head1,head2);
print(multi);

}