#include <iostream>
#include <exception>

using namespace std;

int main() {
    int n;

    cout << "enter the no. of elements in the array : ";
    cin >> n;

    try {
        int* arr = new int[n]; // dynamically creating an array of 'n' elements

        if(arr != nullptr) {
            cout << "enter the " << n << " array elements :" << endl;
            
            for(int i = 0; i < n; i++) { // accepting elements to array
                cin >> arr[i];
            }

            /***************** Selection Sort - Ascending Order ******************/
            int pos, temp, j;

            for(int i = 0; i < n ; i++) {
                pos = i; // assuming a[i] is in the right valur for ith position in sorting order
                for(j = i + 1; j < n; j++) {  
                    // checking if any other element is suitable for ith position in sorting order
                    if(arr[pos] > arr[j]) { /* for descending order change '>' to '<' */
                        pos = j;
                    }
                } // pos will have index of the element suitable for ith position in array

                if(pos != i) { // swapping elements if our assumption was wrong
                    temp = arr[i];
                    arr[i] = arr[pos];
                    arr[pos] = temp;
                }
            }

            cout << "Sorted array :" << endl;
            for(int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
        }
    delete [] arr; // de-allocating dynamic array
    } catch(exception e) {
        std::cerr << "Exception occured :: " << e.what() << endl;
    }

    
    return 0;
}
