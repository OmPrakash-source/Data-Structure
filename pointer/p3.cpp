#include <iostream>
#include <string>
using namespace std;
using namespace std;

int main()
{
    // int ptr[] = {1,2,3,4,5};
    // cout<<"ptr value "<<ptr<<endl;
    // int *str_ptr = ptr;
    // cout<<"str_ptr value "<<str_ptr<<endl;

    // cout<<"pointer subscript nation ------------------"<<endl;
    // cout<<str_ptr[0]<<", ";
    // cout<<str_ptr[1]<<", ";
    // cout<<str_ptr[2]<<", ";
    // cout<<str_ptr[3]<<"\n\n";

    // cout<<"array subscript nation ------------------"<<endl;
    // cout<<ptr[0]<<", ";
    // cout<<ptr[1]<<", ";
    // cout<<ptr[2]<<", ";
    // cout<<ptr[3]<<"\n\n";

    // cout<<"array offset ------------------"<<endl;
    // cout<<*ptr<<", ";
    // cout<<*(ptr + 1)<<", ";
    // cout<<*(ptr + 2)<<", ";
    // cout<<*(ptr + 3)<<"\n\n";

    // cout<<"pointer offset ------------------"<<endl;
    // cout<<*str_ptr<<", ";
    // cout<<*(str_ptr + 1)<<", ";
    // cout<<*(str_ptr + 2)<<", ";
    // cout<<*(str_ptr + 3)<<"\n\n";

    // opration in pointer
    string s1 = "Fark";
    string s2 = "Fark";

    string *ptr_s1 = &s1;
    string *ptr_s2 = &s2;
    string *ptr_s3 = &s1;
    if (ptr_s1 == ptr_s2)
    {                 // for both have a same value then that is true
        cout << true; //     if(*ptr_s1 == *ptr_s2){
    } //         cout<< true;
      //     }

    // int score[] = {100, 95, 99, -1};
    // int *ptr_score = score;
    // while(*ptr_score != -1){
    //     cout<<*ptr_score++ <<" ";
    // }

    // while(*ptr_score != -1){
    //     cout<<*ptr_score<<" ";
    //     ptr_score++;
    // }

    // char name[] = {"Fark"};
    // char *c1 = nullptr;
    // char *c3 = nullptr;

    // c1 = &name[1];
    // c3 = &name[3];
    // cout<<"From name "<< name <<" the latter "<<c1 <<" is " <<(*c1 - *c3) <<" away from "<<c3;

    // pointer in const
    int high_score = 100;
    int low_score = 49;

    int *h1 = &high_score;
    int *l1 = &low_score;
    const int *score_ptr = &high_score; // pointer to const int
    // cout << *score_ptr << endl;
    // // *score_ptr = 34; Error
    // score_ptr = &low_score;
    // cout << *score_ptr << endl;
    cout << "_________________________________ \n";
    int *const score_ptr = &high_score; // pointer to const int
    cout << *score_ptr << endl;
    // *score_ptr = 34;
    // score_ptr = &low_score; // erroe
    cout << *score_ptr << endl;
}