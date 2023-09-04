#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_prime(int a)
{
    if(a<2)
        return 0;
    
    if(a == 2 || a == 3)
        return 1;
    
    if(a%2 == 0 || a&3 == 0)
        return 0;

    //exploit the fact that all primes are of the form 6k +- 1
    int sqrtN = sqrt(a) + 1;
    
    for(int i=5; i<=sqrtN; i+=6){
        if(a%i==0 || a%(i+2)==0)
            return 0;
    }
    
    return 1;
}

int main()
{
    cout << is_prime(-5);
}