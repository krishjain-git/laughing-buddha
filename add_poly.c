#include<stdio.h>
#include<stdlib.h>

struct node 
{
float coef;
int expo;
struct node * link;
};
struct node* insert(float co,int ex,struct node*head)
{

struct node* temp;
struct node *newp=malloc(sizeof(struct node));
newp->coef=co;
newp->expo=ex;
newp->link=NULL;
if(head==NULL||ex>head->expo)
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

struct node *create(struct node *head)
{
int n,i;
int expo;
float coef;
// printf("ENTER THE NUMBER OF TERM YOU WANT TO INSERT IN POLY");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    printf("ENTER THE COEFFICIENT FOR TERM %d\n",i+1);
    scanf("%f",&coef);
    printf("ENTER THE EXPONENT FOR TERM %d\n",i+1);
    scanf("%d",&expo);
    head=insert(coef,expo,head);
}
return head;
}
void print(struct node* head)
{
    if(head==NULL)
    {
        printf("NO POLYNOMIAL");
    }
    else{
    struct node* temp=head;
        while(temp!=NULL)
        {
            printf("(%.1fx^%d)",temp->coef,temp->expo);
            temp=temp->link;
            if(temp!=NULL)
            {
                printf(" + ");
            }
            else
            {
                printf("\n");
            }
        }
    }
}
struct node* poly_add(struct node*head1,struct node*head2)
{
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    struct node*head3=NULL;
    while(ptr1!=NULL&&ptr2!=NULL)
    {
        if(ptr1->expo==ptr2->expo)
        {
            head3=insert(ptr1->coef+ptr2->coef,ptr1->expo,head3);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->expo>ptr2->expo)
        {
         head3=insert(ptr1->coef,ptr1->expo,head3);
         ptr1=ptr1->link;
        }
        else if(ptr1->expo<ptr2->expo)
        {
         head3=insert(ptr2->coef,ptr2->expo,head3);
         ptr2=ptr2->link;
        }
    }
    while(ptr1!=NULL)
    {
        head3=insert(ptr1->coef,ptr1->expo,head3);
        ptr1=ptr1->link;
    }
    while(ptr2!=NULL)
    {
        head3=insert(ptr2->coef,ptr2->expo,head3);
        ptr2=ptr2->link;
    }
    printf("ADDED POLYNOMIAL IS :");
    print(head3);
}
int main()
{
    struct node *head1=NULL;
    struct node *head2=NULL;
    printf("Enter the number of terms you want to insert in first poly\n");
    head1=create(head1);
    printf("Enter the number of terms you want to insert in Second poly\n");
    head2=create(head2);
     printf("First polynomial: ");
    print(head1);

    printf("Second polynomial: ");
    print(head2);

    struct node *sum = poly_add(head1, head2);
    print(sum);

}