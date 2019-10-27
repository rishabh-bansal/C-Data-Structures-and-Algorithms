//A Program in C to insert numbers in linked list and print the numbers by traversing the linked list
//user: namanvats
#include<stdio.h>
#include<stdlib.h>
struct list{
	int data;
	struct list *next;
};
typedef struct list node;
node *head=NULL;
node *create()
	{
		node *temp;
		temp=(node*)malloc(sizeof(node));
		temp->next=NULL;
		return temp;
	}
node* add(int value)
	{
		node *temp,*p;
		temp=create();
		temp->data=value;
		if(head==NULL)
			{
				head=temp;
			}
		else
			{
				p=head;
				while(p->next!=NULL)
					{
						p=p->next;
					}
				p->next=temp;
			}
	}
void display()
	{
		node *p;
		p=head;
		while(p->next!=NULL)
			{
				printf("%d->",p->data);
				p=p->next;
			}
			printf("%d",p->data);
	}
int main()
{
	printf("type -1 to print and terminate else enter any number to add to linked list \n");
	while(1)
	{
		int value;
		scanf("%d",&value);
		if(value==-1)
			{
				display();
				break;
			}
		else
			{
				add(value);
			}
	}
	return 0;
}
