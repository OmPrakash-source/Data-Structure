#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
         cout << "Base class" << endl;
        }
};

class Derived : public Base {
public:
    void display() override {
         cout << "Derived class" << endl; 
         }
};

int main() {
    Base b;;
    b.display();
    Derived D;
    D.display();
    return 0;
}
// minor style fix
