        #include<iostream>
        using namespace std;

        class stack {
            public:
            int *arr;
            int size ;
            int top1;
            int top2;
            stack(int size){
                arr = new int[size]();
                this->size = size;
                top1 = -1;
                top2 = size;
            }
            void push1 (int data){
            if(top2-top1 == 1){         // top is move to left TO right "if stack is empty top is equal to -1"
                cout<<"stack over flow \n";
                return;
            }
            top1++;
            arr[top1] = data;
        }

        void push2(int data){
            if(top2-top1 == 1){       // top is move to right TO left "if stack is empty top is equal to size"
                cout<<"stack over flow \n";
                return ;
            }
            top2--;
            arr[top2] = data;
        }
        void pop1(){
            if(top1 == -1){
                cout<< "stack is underflow\n";
                return ;
            }
            arr[top1]=0;
            top1--;
        }
        void pop2(){
            if(top2 == size){
                cout<<" stack is underflow\n";
                return ;
            }
            arr[top2]=0;
            top2++;
        }
        bool empty1(){
            if(top1 == -1){
                return true;
            }
            else{
                return false;
            }
        }
        bool empty2(){
            if(top2 == size){
                return true;
            }
            else{
                return false;
            }
        }   
        int gettop1(){
            if(top1 == -1){
                cout<<"stack is empty\n";
                return -1;
            }
            return arr[top1];
        }
        int gettop2(){
            if(top2 == size){
                cout<<"stack is empty\n";
                return -1;
            }
            return arr[top2];
        }
        int getsize1(){
            if(top2 == -1){
                return -1;
            }
            return size+1;
        }
        int getsize2(){
            if(top2 == size){
                return -1;
            }
            return size+1;
        }
        void print(){
            cout<<" top 1 = "<<top1<<endl;
            cout<<" top 2 = "<<top2<<endl;
            for(int i =1 ; i<size ; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        };
        
        int main(){
            stack st(8);
            st.print();
            st.push1(1);
            st.print();
            st.push1(3);
            st.push1(5);
            st.push1(7);
            st.push1(9);
            st.push2(11);
            st.push2(13);
            st.push2(15); 
            st.print();
            cout<<st.gettop1()<<endl;
            cout<<st.gettop2()<<endl;
            return 0;
        }