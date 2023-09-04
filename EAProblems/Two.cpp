/*
73011623687142
5679064527730

20802278855542

78690688214872
*/


#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <assert.h>

using namespace std;

char* AddAsciiIntegers(const char* X, const char* Y) {
    std::vector<int> X_Values;
    std::vector<int> Y_Values;

    for (int i = 0; X[i] != '\0'; i++) {
        int digit = X[i] - '0';
        X_Values.push_back(digit);
    }

    for (int j = 0; Y[j] != '\0'; j++) {
        int digit = Y[j] - '0';
        Y_Values.push_back(digit);
    }

    // Reverse the vectors to do operations starting from ones column
    std::reverse(X_Values.begin(), X_Values.end());
    std::reverse(Y_Values.begin(), Y_Values.end());

    int X_Size = X_Values.size();
    int Y_Size = Y_Values.size();
    int greater = (X_Size >= Y_Size) ? X_Size : Y_Size;

    bool carryOver = false;
    std::string build_string = "";

    for (int i = 0; i < greater || carryOver; i++) 
    {
        int sum = (i < X_Size ? X_Values[i] : 0) + (i < Y_Size ? Y_Values[i] : 0);
        if (carryOver)
            sum += 1;

        if (sum >= 10) {
            carryOver = true;
            sum -= 10;
        } else {
            carryOver = false;
        }
        build_string += std::to_string(sum);
    }

    // Reverse before building return value
    std::reverse(build_string.begin(), build_string.end());

    char* sol = new char[build_string.size() + 1];

    for (size_t i = 0; i < build_string.size(); i++)
        sol[i] = build_string[i];

    sol[build_string.size()] = '\0';

    return sol;
}


int main() {
    const char* a = "700";
    const char* b = "100";

    const char* res = AddAsciiIntegers("700", "100");
    std::cout << res << std::endl;

    delete[] res; // Free the allocated memory

    return 0;
}