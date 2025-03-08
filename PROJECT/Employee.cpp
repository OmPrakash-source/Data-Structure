    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <numeric>
    #include <iterator>
    #include <string>

    using namespace std;

    struct Employee{
        int id;
        string name;
        double salary;
    };

    void dispalyEmployee(const Employee& emp){ // after using amparsent only pass refrence without pointing any addrease
        cout<< "ID: "<<emp.id<<" ,Name: "<<emp.name<<" ,Salary $"<<emp.salary << endl;


    }

    int main(){

        vector<<Employee>employees> = {
            {101 ,"Omprakash ", 350000},
            {102 ,"Hardik ", 200000},
            {103 ,"Akash ", 250000},
            {104 ,"Anurag ", 150000},
            {105 ,"Rohit ", 130000},
        };

        sort{employees.being(), employees.end(),[](){}};
        return 0;
    }