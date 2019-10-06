/*


          * * 
          * * 
        * * * * 
        * * * * 
      * * * * * * 
      * * * * * * 
    * * * * * * * * 
    * * * * * * * * 
  * * * * * * * * * * 
  * * * * * * * * * * 
* * * * * * * * * * * * 
* * * * * * * * * * * * 


*/
#include <iostream> 
using namespace std; 
void double_staircase(int n) 
{ 
   
    for (int i = 1; i <= n; i++) { 
  
        int k = (i % 2 != 0) ? i + 1 : i; 
        for (int g = n; g > k; g--) 
            cout << " "; 
        for (int j = 0; j < k; j++) 
            cout << "* "; 
        cout << endl; 
    } 
} 
int main() 
{ 
    int n = 6; //this is the number of stairs
    n=n*2;
    double_staircase(n); 
    return 0; 
} 

