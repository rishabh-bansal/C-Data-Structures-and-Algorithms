#include <iostream>
#include <string>
#include <math.h>
// d is the number of characters in the input alphabet
#define d 256
using namespace std;
void main()
{
    int q = 101; // A prime number
    string originalString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string pattern = "IJK";
    bool patternFound = true;
    int n = originalString.length(); //size of original string
    int m = pattern.length();        //size of pattern
    int t = 0;                       //hash value of original string
    int p = 0;                       //hash value of pattern
    int i, j;
    int h = 1;
    //pow(d,M-1)%q
    for (i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + originalString[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (originalString[i + j] != pattern[j])
                    break;
            }

            if (j == m)
            {
                cout << "Pattern found at index " << i << endl;
                break;
            }
        }

        if (i < n - m)
        {
            t = (d * (t - originalString[i] * h) + originalString[i + m]) % q;
            if (t < 0) //if value is negative
            {

                t = (t + q);
            }
        }
    }
    system("pause");
}