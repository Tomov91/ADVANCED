#include<vector>
#include<algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector<int> myVec = { 1,5,7,25,43,13 };
    for_each(myVec.begin(), myVec.end(), [](int x) {cout << x << " "; }); // first example

    /*[](int a) {
        if ( a % 2 == 0) {
            cout << a << " ";         Second example
        }
    }*/ 

   /* Second Example for_each(myVec.begin(), myVec.end(), [](int a) {
        if (a % 2 == 0) {
            cout << a << " is even" << endl;
        }
        else
        {
            cout << a << " is not even" << endl;
        }
        });
        */
    int d = 3;
        for_each(myVec.begin(), myVec.end(), [d](int a) {
        if (a % d == 0) {
            cout << a << " is divisible by " << d << endl;
        }
        else
        {
            cout << a << " is not divisible by" << d << endl; 
        }
        });
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
