#include <algorithm>
#include <iostream>

using namespace std;



int main()
{
    int a = 15;
    int &b = a;
    cout << clamp(b,14,0,greater<int>()) << endl;

    cout << b;
}