#include <iostream>
#include <string>
using namespace std;
void main()
{
    string originalString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string pattern = "IJKB";
    bool patternFound = true;
    int i = -1;
    int size = originalString.length();
    while (i < size)
    {
        patternFound = true;
        for (int j = 0; j < pattern.length(); j++)
        {
            i++;
            if (pattern[j] != originalString[i])
            {
                patternFound = false;
                break;
            }
        }
        if (patternFound == true)
        {
            cout << "Pattern found at: " << i << endl;
            break;
        }
    }
    if (patternFound == false)
    {
        cout << "Pattern wasn't found " << endl;
    }
    system("pause");
}