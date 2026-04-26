// concept come after shared pointer first create shared ptr
// there if multiple shared pointer have so if we want to delete a resource then resat ownership of all
// So use weak pointer so only sharedptr is owner of resouce or all weak pointer point to same resource if use_count = 0 then resource is free
// weak pointer se use_count increass nhi hota hai "" agar shared ptr kisi or shared ptr ko shear karega ko use count incress hoga
// weak pointer dependent on shared_ptr if it not point or reset then weak also reset by defoalt
#include<iostream>
#include<memory>
using namespace std;

int f1(){
    shared_ptr<int>p1 (new int(10));
    weak_ptr<int>p2;
    p2 = p1;
    cout<<"P1 ki val: "<<*p1<<endl;
    cout<<"But p2 *(p1.lock()) call not same as *p1 " ;
    cout<<*(p2.lock())<<endl;
    cout<<"shared_ptr: "<<p1.use_count()<<endl;
    cout<<"weak_ptr: "<<p2.use_count()<<endl;

    // p1.reset();
    // cout<<"shared_ptr: "<<p1.use_count()<<endl;
    // cout<<"weak_ptr: "<<p2.use_count()<<endl;

    p2.reset();
    cout<<"shared_ptr: "<<p1.use_count()<<endl;
    cout<<"weak_ptr: "<<p2.use_count()<<endl;

}
int main(){
    f1();
}