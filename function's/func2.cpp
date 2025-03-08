    #include<iostream>
    #include<vector>
    using namespace std;


     // New for loop condition

     void table(vector<int>vt){

        for(int v : vt){
            cout<<v<<" ";
        }
        cout<<endl;
     }
    
    // pass by value 
    // there we can pass only copy
    void a(int s){
        s = 40;
        cout<< "pass by value: "<< s <<endl;
    }

    // pass by refreance
    // there we can change value in main function
    void b(int &s){
        s = 20;
        cout<< "pass by refreance: "<< s <<endl;
    }

     int main(){
        vector<int>vt ={2,4,6,8,10,12,14,16,18,20};
        table(vt);
        int s = 10;
        a(s);
        cout<< "with out change value: "<< s <<endl;
        b(s);
        cout<< "after change value: "<< s <<endl;
     }