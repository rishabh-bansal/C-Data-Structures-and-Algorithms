#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 5

int stack [SIZE],top=0;
void push();
void pop();
void display();
main()
{
	int choice;
	while(1)
	{
		printf("--main menu--");
		printf("1.\n push); 
		printf("2. \n pop" );
		printf("3.\n display");
		printf( "4.\n exit(0)");
		printf("enter your choice (1-4)");
		
		switch(choice)
		{
			case 1:push();
			       break;
			       
			       
			case 2:pop();
			       break;
				   
		    case 3:display();
			       break;
				   
	        case 4:exit(0);
						   		          
		}
		
		
		
		}
}




void push()
{
	if(top>=SIZE)
	{
		printf("stack is overflow");
	}
	else
	{
		printf("\n enter the value");
		scanf("%d",&stack [top]);
		top++;
	}
}//end of push();

void pop()
{
	if(top<=0)
	{
		printf("\n stack is overflow");
		
	}
	else
	top--;
	printf("deleted value =%d",stack[top]);
}// end of pop//

void display()
{
	int i;
	for(i=0;i<top;i++)
	{
		printf("\n %d",stack[i] );
	}
}

// end of display///
