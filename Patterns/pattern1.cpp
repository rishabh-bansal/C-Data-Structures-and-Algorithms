#include <iostream>
using namespace std;

int main(){

/*take n to be the number of rows*/
/*declaring the variable n*/

	int n;

/*taking value of n as input from the user*/

	cin >> n;

/*implementing a for loop row by row*/
/*initializing variable i=0 within for loop*/
/*total number of times the first for loop will run will be equal to n*/

	for( int i = 0; i < n; i++ ){

/*initializing a variable j=0 in second loop*/
/*the second loop will run n times*/

		for( int j = 0; j < n; j++ ){

/*priting asterisk (*) without space for the pattern*/

			cout << "*";
		}

/*once the loop with j variable is complete, cursor will be shifted to new line*/

		cout << endl;
	}
    return 0;
}

/*
At n=5, output:

5

*****
*****
*****
*****
*****

*/
