#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


# define SIZE 10
int stack [SIZE],top[2]={0,SIZE-1};
void push(int s); // s= stack
void pop(int s);
void display(int s);

main(){
	int choice, s;
	while(1)
	{
		printf("\n main menu");
		printf("\n 1.push 2.\n pop 3.\n display \n 4.exit");
		printf("\n enter your choice(1-4):");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n enter the stack no:");
				scanf("%d",&s);
				push(s);
				break;
				
				
			case 2:
				printf("\n enter the stack no:");
				scanf("%d",&s);
				pop(s);
				break;
		    case 3:
				printf("\n enter the stack no:");
				scanf("%d",&s);
				display(s);
				break;
		}
	}
}

void push(int s)
{
	int i;
	i =s-1;
	if(top[0]<=top[1])
	{
		printf("\n enter the no:");
		scanf("%d",&stack[top[i]]);
		if(i==0)
		{
			top[0]++;
			
		}
		else  
		{
			top[1]--;
		}
    }
		
		else
		
		{
				printf("\n stack is overflow:");
		}
	
	
	}
  /// end of push()///

void pop(int s)
{
	if(s==1 && top[0]>0)
	{
		top[0]--;
		printf("\n deleted value =%d",stack [top[0]]);
	}
	else if (s==2 &&top[1]<SIZE-1)
	{
		top[1]--;
		printf("\n deleted value =%d",stack [top[1]]);
	}
	
    else
	{
		printf("\n stack is underflow");
	}
}

// end of pop();

void display(int s)
{
	int i;
	if(s==1&& top[0]>0)
	{
		for(i=0;i<top[0];i++)
		{
			printf("%d \n",stack[i]);
		}
		
	}
	else if (s==2&&top[1<SIZE-1])
	{
		for(i=SIZE-1;i>top[1];i--)
		{
			printf("%d \n",stack[i]);
		}
	}

		else
		{
			printf("\n stack is underflow");
		}
}


