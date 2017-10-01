#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;

	for( int i = 0; i < n; i++ ){        //Iterate over n rows 
		for( int j = 0; j <= i; j++ ){  // Number of columns will be equal to one more than the row number (since rows are 0 indexed )
			cout << "*";
		}
		cout << endl;
	}

    return 0;

}

/*
5

*
**
***
****
*****
*/
