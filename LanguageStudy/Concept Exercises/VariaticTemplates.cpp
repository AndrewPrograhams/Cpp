#include <iostream>

using namespace std;

void print()
{
    cout << endl;
}

template <typename T> void print(const T& t){
    cout << t << endl;
}

template <typename First, typename... Rest> void print(const First& first, const Rest& ...rest)
{
    cout << first << ", ";
    print(rest...);
}

int main()
{
    print();
    print(1);

    print(10,20);
    print(10,20, "third", "fourth");
}