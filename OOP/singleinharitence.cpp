    #include <iostream>
    #include <cmath> 

    using namespace std;

// base class
    class Employee{
        public:
        int id;
        float salary;
        Employee(){} // constructor 

        Employee(int id){
            salary = 86000.64;
        }
    };

// derived class
    class Programmer : protected Employee{
        
        string skill;
        public:
        
            void print(int id,float salary ,string skill){
                this->skill = skill;
                cout<<"Employee id: "<< id << 
                endl<<"Employee salary: "<< salary <<
                endl <<"Skill's of employee: "<< skill<<endl;
            }
    };

    int main(){
        Programmer programmer1, programmer2;
        programmer1.print(21, 89300, "Omprakash");
        programmer2.print(22, 89030, "hardik");
    }
// minor style fix
