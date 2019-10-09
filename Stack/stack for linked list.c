#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack
{
	int info;
	struct stack *next;
	
};
struct stack *start=NULL;
void push(int n);
void pop();
void display();
main()
{
	int  n, choice;
	while(1)
	{
		printf("--main menu--");
		printf("1.\n push node"); 
		printf("2. \n pop node" );
		printf("3.\n display node");
		printf( "4.\n exit()");
		printf("enter your choice (1-4)");
		scanf("%d",&choice);
		
		
		switch(choice)
		{
			case 1:
				printf("\n enter the value:");
				scanf("%d",&n);
				push(n);
				break;
			       
			       
			case 2:pop();
			       break;
				   
		    case 3:display();
			       break;
				   
	        case 4:exit(0);
						   		          
		}
		
		}
}// end of main()//

void push(int n)
{
	struct stack *node,*temp;
	if(start==NULL)
	{
	    node=((struct stack*) malloc(sizeof (struct stack)));
		node->info=n;
		node->next=NULL;
		start=node;
	}
	else
	{
		node=start;
		while(node->next!=NULL)
		{
			node=node->next;
		}
		temp=((struct stack*) malloc(sizeof (struct stack)));
		temp->info=n;
		temp->next=NULL;
		temp->next=temp;
	}
}


void pop()
{
	struct stack *prev,*node;
	prev= start;
	if (start==NULL)
	{
		printf("stack is underflow");
	}
	else if(prev->next==NULL)
	{
		start=NULL;
		free(prev);
	}
	else
	{
		node=prev->next;
		while(node->next!=NULL)
		{
			node=node->next;
			prev=prev->next;
		}
		prev->next=NULL;
		free(node);
	}
}
//end of pop()
void display()
{
	struct stack *node;
	node= start;
	while(node!=NULL)
	{
		printf("%d \n",node->info);
		node=node->next;
	}
}// end od display()///




