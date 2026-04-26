// it maintains reference counting ownership of its contained pointer in cooperation with all copies of the shared_ptr
#include<iostream>
#include<memory>
using namespace std;
void f1(){
    shared_ptr<int>p1 (new int(10));
    shared_ptr<int>p2;
    p2 = p1; // there it both point to same value ownership dono ke pass hai
    cout<<"P1 is "<<p1.use_count()<<" and P2 is "<<p2.use_count()<<endl; //there both or two pointer are point to same resource


    cout<<"P1 ka address "<<p1.get()<<endl; // same 
    cout<<"P2 ka address "<<p2.get()<<endl; // same 


    //now p1 can not point that resource
    p1.reset();
    cout<<"P1 is "<<p1.use_count()<<" and P2 is "<<p2.use_count()<<endl;
    //there both or p1 pointer point null and p2 pointer are point to same resource

    cout<<"P1 ka address "<<p1.get()<<endl;// ye koi ko point nhi kar ra 
    cout<<"P2 ka address "<<p2.get()<<endl;
}
int main(){
    f1();
    return 0;
}

// minor style fix
