#include <iostream>

class Money {
private:
    double amount;

public:
    explicit Money(double a) : amount(a) {}  // Notice the 'explicit' keyword

    void show() const {
        std::cout << "$" << amount << std::endl;
    }

    void spend(Money m) {
        std::cout << "Spending ";
    m.show();
    }
};


int main(){
    Money m(100);
    // m.spend(100.0); //invalid due to explicit keyword
    m.spend(Money(100)); // explicit call to constructor, implicit conversion to double.
}