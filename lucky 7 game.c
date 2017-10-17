#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\t\t\t\t********welcome to LUCKY 7 GAME*********\t\t\t\t\t\n\n");
    int n,choice,amt;
    char ch;
    srand(time(NULL));
    n=rand()%15;
    printf("Please enter the amount you want to put at stake : ");
    scanf("%d",&amt);


    do
    {
        printf("please select one option from below : \n");
        printf("1. Below 7\n");
        printf("2. On 7\n");
        printf("3. Above 7\n");
        printf("Please enter your choice : ");
        scanf("%d",&choice);


        switch(choice)
        {
        case 1:
            if(n<7)
            {
                printf("\nCongrats!! you won %d rupees\n",2*amt);
            }
            else
            {
                printf("\nSorry you lost %d rupees\n",amt);
            }
            break;
        case 2:
            if(n==7)
            {
                printf("\nCongrats!! you won %d rupees\n",3*amt);
            }
            else
            {
                printf("\nSorry you lost %d rupees\n",amt);
            }
            break;
        case 3:
            if(n>7)
            {
                printf("\nCongrats!! you won %d rupees\n",2*amt);
            }
            else
            {
                printf("\nSorry you lost %d rupees\n",amt);
            }
            break;
        default:
            printf("Please enter a no. between 1 and 3");

        }
        printf ("\nDo you want to play the game again Y/N: ");
        scanf (" %c", &ch);
}
while (ch == 'y' || ch == 'Y');

    return 0;
}
