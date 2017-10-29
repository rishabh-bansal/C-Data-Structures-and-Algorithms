#include<iostream>

using namespace std;

/*

It will print an inverted alphabet triangle

Example:

ABCDCBA
 BCDCB
  CDC
   D

*/

int main()
{
    int rows, space=0, alpha=65, counter;
    cin>>rows;

    for (int i=0; i<rows; i++)
    {
        //Printing left space
        for (int j=0; j<space; j++)
        {
            cout<<" ";
        }

        counter=alpha;
        //Printing alphabet till mid row
        while (counter<65+rows)
        {
            cout<<(char)counter;
            counter++;
        }

        counter=63+rows;
        //Printing alphabet after it
        while (counter>=alpha)
        {
            cout<<(char)counter;
            counter--;
        }

        //Moving to next line
        cout<<'\n';

        //Incrementing starting letter and space
        alpha++;
        space++;
    }
}
