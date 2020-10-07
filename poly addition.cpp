#include<stdio.h>
#include<stdlib.h>
struct node{
int coeff, expo;
struct node *next;
};

struct node* create()
{
	struct node *head=NULL, *newptr, *ptr;
	printf("Enter the polynomial in decreasing power of x and must end with x^0:");
do{
    newptr=malloc(sizeof(struct node));
	scanf("%d", &newptr->coeff);
	printf("x^");
	scanf("%d",&newptr->expo);
	if(newptr->expo!=0)
	  printf("+");
	newptr->next=NULL;
	if (head==NULL){
		head=newptr;
		ptr=head;	
	}
	else{
	  ptr->next=newptr;	
	  ptr=newptr;
	}
}while(newptr->expo!=0);
return head;
}


void show(struct node* head)
{
while(head!=NULL){
	printf("(%dx^%d)",head->coeff,head->expo);
	if(head->expo!=0)
	  printf("+");
	head=head->next;	
}
}

struct node* add(struct node *poly1, struct node *poly2)
{
	struct node *head=NULL, *ptr=NULL, *newptr=NULL;
	while(poly1 && poly2)
	{ 
	    newptr=malloc(sizeof(struct node));
	    newptr->next=NULL;
		if (poly1->expo>poly2->expo)
		{
		   newptr->coeff=poly1->coeff;
		   newptr->expo=poly1->expo;
		   poly1=poly1->next;
		}
		else if(poly1->expo<poly2->expo)
		{
		   newptr->coeff=poly2->coeff;
		   newptr->expo=poly2->expo;
		   poly2=poly2->next;
		}
		else
		{
		   newptr->coeff=poly1->coeff+poly2->coeff;
		   newptr->expo=poly1->expo;
		   poly2=poly2->next;
		   poly1=poly1->next;
		}
	    if (head==NULL){
		 head=newptr;
		 ptr=head;
	    }
		else
		{
		   ptr->next=newptr;
		   ptr=newptr;
	    }
	}
   return head;
}
int main(){
	struct node *poly1, *poly2, *sum;
   poly1=create();
   poly2=create();
   printf(" 1st polynomial :");
   show(poly1);
   printf("\n 2nd polynomial :");
   show(poly2);
   sum=add(poly1,poly2);
   printf("\n sum :");
   show(sum);
   return 0;
}
