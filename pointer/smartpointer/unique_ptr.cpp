 //we can't assign one pointer value to other by using = oprateor or copy construcor
// unique ptr is a container for a row pointer

#include<iostream>
#include<string>
#include<memory>
using namespace std;
void f1(){
    // int *ptr = new int [10];
    // if(*ptr == 10){
    //     return *ptr;  // but when it return then |
    //     delete ptr;   // it's not delete a pointed value so memory leak
    // }

//___________________________________________________________________________________________________________________________________________________

    unique_ptr<int>p(new int(10)); // we use smart unique pointer it is a template type class whice automatic delete dynamic pointer value when function call is finish
                // that is row pointer new int[10] when p destroy row pointer also delete it self
    cout<<*p<< " is int value"<<endl;
//___________________________________________________________________________________________________________________________________________________
// for assing null to any other

    unique_ptr<string>st;  // now it point to NULL when we (reset) it that mean first call destructor then ptr point new value in st;
    st.reset(new string("hello"));
    cout<<*st << " is string value assing by NULL then new"<<endl;
//___________________________________________________________________________________________________________________________________________________
// assing value of one ptr to another 

    unique_ptr<int>p1(new int(10));
    unique_ptr<int>p2;
    cout<<*p1<<endl;
    p2 = move(p1);
    if(p1 == NULL){
        cout<<"P1 is point to NULL becouse ownership is given to P2 \n";
    }else{
        cout<<*p1<<endl;
    }
    cout<< "P2 is new owner of the value "<<*p2<<endl;

//___________________________________________________________________________________________________________________________________________________
}
int main(){
    f1();
}