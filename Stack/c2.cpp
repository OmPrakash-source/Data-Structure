    #include<iostream>
    using namespace std;
    class Stack{
        public:
        int *arr;
        int size;
        int top;

        // contructor
        Stack(int size){
            arr = new int[size];
            this->size = size; // this use " use same name in diff value "
            this->top = -1;
        }
        // Push 
        void push(int data){
            if(top == size-1){
                cout<<"Stack is overflow \n";
                return;
            }
            else{
                top++;
                arr[top] = data;
            }
        }

        //pop
        int pop(){
            if(top == -1){
                cout<<"stack is underflow \n";
                return -1;
            }
            else{
                top--;
            }
        }

        //empty 
        bool Isempty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }

        //top element
        int gettop(){
            if(top == -1){
                cout<<"stack is empty \n";
                return -1;
            }
            return arr[top];
        }

        // size 
        int getsize(){
            return top+1;
        }

        void print(){
            cout<< "Top: "<<top<<endl;
            cout<< "Top element  "<<gettop()<<endl;
            cout<<"size "<<getsize()<<endl;
            cout<< "Stack ";  
            for(int i=0 ; i<getsize() ; i++){
                cout<<arr[i] <<" ";
            }
            cout<<"\n"<<endl;
        }
    };
    int main(){
        Stack st(5);

        st.push(10);
        st.print();

        st.push(20);
        st.print();

        st.push(30);
        st.print();

        st.push(40);
        st.print();

        st.push(50);
        st.print();

        st.push(60);
        st.print();

        st.pop();
        st.print();
    }
// minor style fix
