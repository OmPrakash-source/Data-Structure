// it varify binary search tree
#include<iostream>
#include<vector>
using namespace std;    
class Heap{
    vector<int>vec;
    void heapify(int i){
        if(vec[i] >= vec[vec.size()]){
            return;
        }
        int l = 2*i+1;
        int r = 2*i+2;
        int maxIdx = i;
        if(l < vec.size() && vec[l] > vec[maxIdx]){
            maxIdx = l;
        }
        if(r < vec.size() && vec[r] > vec[maxIdx]){
            maxIdx = l;
        }
        swap(vec[i],vec[maxIdx]);
        if(maxIdx != i){
            heapify(maxIdx);
        }
    }
    public:
        void push(int val){
            vec.push_back(val);
            int child = vec.size()-1; // last jo push hui hai ya child
            int parI = (child-1)/2;
            // min heap only change(>) vec[parI] < vec[child]
            while(vec[parI] < vec[child] && parI >= 0){ //0(logn) 
                swap(vec[parI],vec[child]);
                child = parI;
                parI = (child-1)/2;
            }
        }
        void pop(){
            // step 1 swap idx[0],last idx ke sath
            swap(vec[0],vec[vec.size()-1]);
            //step 2 delete top value
            vec.pop_back();
            //step 3 fix using heapify 
            heapify(0);
            
        }
        int top(){
            return vec[0]; // height value
        }
        int empty(){
            return vec.size() == 0;
        }
};

int main(){
    Heap heap;
    heap.push(50);
    heap.push(100);
    heap.push(10);
    
    cout<<"top "<<heap.top()<<endl;
    heap.pop();
    cout<<"top "<<heap.top()<<endl;
    cout<<heap.empty()<<endl;
    return 0;
}