    #include<iostream>
    using namespace std;

    // in this case we use dynamic memory

    int* returnArr(int num){
        int* arr = new int[num];
        for(int i=0; i<num; i++){
            arr[i] = (i+1)*10;
        }
        return arr;
    }
    int main(){
        int num = 5;
        int* A = returnArr(num);

        for(int i=0; i<num; i++){
            cout<<A[i]<<" ";
        }
        // Delete array from dynamic memory
        delete[] A;
    return 0;
    }
// minor style fix
