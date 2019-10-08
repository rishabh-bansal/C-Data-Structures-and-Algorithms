#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct list{
	int info;
	struct  list *prev , *next;	
};

struct list *start = NULL;
void insert_node(int n);
void delete_node();
void display();


main()
{
	int n,choice;
	while(1)
	{
		
		printf(" main menu");
		printf("1.\n insert node");
		printf("2.\n delete node");
		printf("3.\n display node value");
		printf("4. \n exit");
		printf("enter your choice (1-4);");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:printf("enter the value");
		           scanf("%d",&n);
		           insert_node(n);
		           break;
		           
		           
	        case 2: delete_node();
	                break;
	                
	        case 3:display();
			       break;
			       
			case 4:exit(0);
				           
		 }  
	}
}

void insert_node(int n)
{
	struct list *node,*temp;
	if(start==NULL)
	{
		
	    node=((struct list *)malloc(sizeof(struct list)) );
		node->info=n;
		start=node;
		node->next=start;
	}
	else
	{
		node=start;
		
		while(node->next!=start)
		{
			node=node->next;
		}
		temp=((struct list *)malloc(sizeof(struct list)) );
		temp->info=n;
		temp->next=start;
		node->next=temp;
	}
}


void delete_node()
{
	struct list *prev,*node;
	prev =start;
	node =prev->next;
	
	if (prev->next==start)
	{
		start=NULL;
		free(prev);
	}
	else
	{
		node= prev->next;
		
		while(node->next!=start)
		
		node=node->next;
		prev=prev->next;
	}
	prev->next=start;
	free(node);
}

void display()
{
	struct list *node;
	node=start;
	
	do
	{
		printf("%d \n",node->info);
		node=node->next;
		
	}
	while(node!=start);
}
