#include <iostream>
#include <string>
using namespace std;

int main() {
    /*
    // ----------------------------------------
    // 📌 Address Operator & sizeof
    char num{'A'};
    cout << "Size of variable (char): " << sizeof num << " byte(s)" << endl;
    cout << "Address of variable 'num': " << &num << endl;
    cout << "Value of variable 'num': " << num << endl;


    // ----------------------------------------
    // 📌 Pointer and Reference
    int x = 10;
    int* e = &x;              // pointer to x
    int& y = x;               // reference to x
    int& z = y;               // reference to reference (same as x)

    cout << "*e (value of x): " << *e << endl;
    cout << "&z (address of x): " << &z << endl;

    // ❌ Do NOT delete stack memory
    // delete e; // ❌ invalid - removed

    // ----------------------------------------
    // 📌 Null Pointer
    int* name{}; // same as int* name = nullptr;
    cout << "Null pointer value (name): " << name << endl;

    // ----------------------------------------
    // 📌 Uninitialized Pointer (fixed)
    cout << "\n__________________________________\n";
    int value = 50;
    int* p = &value;  // ✅ initialize pointer

    cout << "Value pointed by p: " << *p << endl;
    cout << "Address of p variable itself: " << &p << endl;
    cout << "Size of pointer p: " << sizeof p << " byte(s)" << endl;

    p = nullptr;
    cout << "p after assigning nullptr: " << p << endl;

    // ----------------------------------------
    // 📌 Dereferencing Pointers
    cout << "\n__________________________________\n";
    int score{100};
    int* ptrscore{&score};

    cout << "*ptrscore (initial): " << *ptrscore << endl;
    cout << "&score: " << &score << endl;

    *ptrscore = 200; // changing value via pointer
    cout << "*ptrscore (after change): " << *ptrscore << endl;
    cout << "score (after change): " << score << endl;

    // ----------------------------------------
    // 📌 Pointer Reassignment
    cout << "\n__________________________________\n";
    double high_temp{100.7};
    double low_temp{37.7};
    double* temp_ptr{&high_temp};

    cout << "High temp via pointer: " << *temp_ptr << endl;

    temp_ptr = &low_temp; // now points to low_temp
    cout << "Low temp via pointer: " << *temp_ptr << endl;

    // ----------------------------------------
    // 📌 String and Pointer
    cout << "\n__________________________________\n";
    string str_name{"Jamms"};
    string* str_first{&str_name};

    cout << "Initial string: " << *str_first << endl;
    str_name = "happy"; // string content changed
    cout << "Updated string: " << *str_first << endl;

    // ----------------------------------------
    // 📌 Integer Pointer Example
    cout << "\n__________________________________\n";
    int num_val = 300;
    int* str_ptr = &num_val;

    cout << "Initial num_val via pointer: " << *str_ptr << endl;

    *str_ptr = 150; // update through pointer

    cout << "Updated num_val via pointer: " << *str_ptr << endl;
    cout << "Updated num_val directly: " << num_val << endl;*/

//📌 Dynamic Pointer Example
    int *ptr{nullptr};
    ptr = new int; // dynamically allocate memory
    cout <<"Address of garbage value "<< ptr <<endl;
    cout <<"ptr garbage value "<< *ptr <<endl;
    *ptr = 100;
    cout <<"Address of value (it same as garbage value) "<< ptr <<endl;
    cout <<"updated ptr value "<< *ptr <<endl;
    delete ptr; //free the allocation 

//📌 Dynamic array Pointer Example   
    size_t size{0};
    double *array_ptr = nullptr;
    cout<<"Enter size of array ";
    cin>>size;
    array_ptr = new double[size];
    cout<<array_ptr<<endl;
    array_ptr = nullptr;
    cout<<array_ptr<<endl;
    delete []array_ptr;
    return 0;
}
