    #include<iostream>
    using namespace std;

//___________________ base class ___________________

    class Base{
        int data1;
        int data2;
        public:

            void put();
            int get1();
            int get2();

    };

    // declearation of class out-side of class
    void Base :: put(){
        data1 = 23;
        data2 = 05;
    }
    int Base :: get1(){
        return data1;
    }
    int Base :: get2(){
        return data2;
    }

    class Derived : public Base{
        int data3;
        public:
            int process(){
                data3 =  get2() + get1();
                return data3;
            }
            void display(){
                cout << "data1 (private, accessed via get1): " << get1() << endl;
                cout << "data2 (private, accessed via get2): " << get2() << endl;
                cout << "data3 (calculated): " << data3 << endl;
            }
    };

    int main(){
        Derived d1;
        d1.put();
        d1.process();
        d1.display();
    }

// minor style fix
