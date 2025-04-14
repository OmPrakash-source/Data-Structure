    #include<iostream>
    #include<stack>
    using namespace std;
    int main(){

        // using SLD 
        
// ________________________________create ________________________________
    stack<int>st;

// ________________________________insertion ________________________________
    st.push(10);
    st.push(20);
    st.push(30);  // It push last that it's a top of stack

//________________________________ size ________________________________
    cout<<" Size of stack: "<<st.size()<<endl;

//________________________________ top of stack ________________________________
    cout << " Top of stack: "<<st.top()<<endl;

//________________________________ remove ________________________________
    st.pop();   // becuse TOS is point to 30 that's 30 is remove first 
    st.pop();
    st.pop();

//________________________________ empty ________________________________
    if(st.empty()){
        cout<<" Stack is empty \n";
    }
    else{
        cout<<" Stack is not empty \n";
    }
    
//______________________________ Revesr an string ________________________________

    string str = "hsakarpmo";
    stack<char> Nst;
    for(int i = 0; i<str.length();i++){
        char ch = str[i];
        Nst.push(str[i]);
    }
    cout<<" Reverse String is: ";
    while(!Nst.empty()){
        cout<< Nst.top();
        Nst.pop();
    }
    cout<<endl;
    }