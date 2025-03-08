#include<iostream>
#include<string>
using namespace std;
int fun1(){
    return 4;
}
int fun2(){
    return 3;
}
int main(){
    int arr[] = {1,2,3};
    cout<<arr[1]<<endl;
    cout<<fun1()*fun2();

    return 0;
}