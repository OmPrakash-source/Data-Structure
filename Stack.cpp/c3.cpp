    #include<iostream>
    #include<stack>
    using namespace std;

//________________________________________ find and delete mid _____________________________________________
    int solve(stack<int>& st,int posi ){
        if(posi == 1){
           int ans = st.top();
           return ans;
        }

        int temp = st.top();
        st.pop();
        // recurtion 
        int ans = solve(st,posi-1);

        // backtreaking 
        st.push(temp);
        return ans;
    }
    int middle(stack<int>& st){
        int size = st.size();
        // agar stack empty ho 
        if(st.empty()){
            return -1;
        }
        else{
            int posi = 0;
            // if position is odd 
            if(size%2 == 1){
                posi = (size/2) + 1;
            }
            // if position is even (2,4,6) 
            else{
                posi = size /2;
            }

        return solve(st , posi);
        }  
    }
//________________________________________ Insert into buttom _____________________________________________
    void insertAtbot(stack<int>& st ,int val){
        if(st.empty()){
            st.push(val);
            return;
        }
        int temp = st.top();
        st.pop();
        insertAtbot(st , val);
        st.push(temp);
    }
    
//_______________________________________________ reverse __________________________________________________
    void reverse(stack<int> &st){
        if(st.empty()){
            return;
        }
        int temp = st.top();
        st.pop();

        //recursion
        reverse(st);

        // backtreaking
        insertAtbot(st,temp);
    }
//_____________________________________ Reinsert in sorted new Stack _______________________________________
    void SortedArr(stack<int> &st , int val){
        if(st.size()==0 ||st.top() < val){
            st.push(val);
            return;
        }
        int temp = st.top();
        st.pop();

        SortedArr(st,val);
        st.push(temp);
    }

//_____________________________________ Sort A exixting Stack ________________________________________________
    void SortStack(stack<int> &st){
        if(st.empty()){
            return;
        }
        int temp = st.top();
        st.pop();

        SortStack(st);

        SortedArr(st ,temp);
    }
    int main(){
        stack<int>st;
        st.push(10);
        st.push(60);
        st.push(40);
        st.push(30);
        st.push(20);
        st.push(50);

    // cout<< " middle of stack : "<<middle(st)<<endl<<endl;
       cout<< " size before push "<<st.size()<<endl;
    // insertAtbot(st,400);
    // SortedArr(st , 5);
        SortStack(st);
       cout<< " size after push "<<st.size()<<endl<<endl;
       cout << "Stack elements after insertion: ";

    // reverse(st);
    // print stack 

        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
}