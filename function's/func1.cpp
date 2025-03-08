    #include<iostream>
    #include<string>
    using namespace std;

    //function declearation 
    int func(int num1);


    //function overloding by parameter
    int func(string st ,string sr){
        cout<<"string are: "<<st+sr<<endl;
        for(char s : st){
            cout<<s;
        }
        cout<<endl;
        return 0;
    }

    //predefind parameter 
    double func(float a = 10.32 , float b = 0){
        cout<<"float "<<a<<" + "<<b<<" = "<<a+b<<endl;
        return a;
    }

   

    int main(){
        cout<< "function declearation of func: "<<func(40)<<"\n";

        cout<< "overloded function are: "<<func("om","prakash")<<"\n";

        cout << "Function with default parameters: " << func() << "\n";
        return 0;


    }

    //function defination

    int func(int num1){
        int num2 = 30;
        cout<<"sum: "<<num1<<" + "<<num2<<" = "<<num1+num2<<endl;
        return num1;
    }