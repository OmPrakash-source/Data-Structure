#include<iostream>
using namespace std;
//______________________________________ reverse problem _________________________________________   
        void reverse( int n){
            if(n==0){
                return ;
            }
            cout<<n<<" ";
            reverse( n-1 );
        }
//______________________________________ fibonacci problem _________________________________________   
        int fibo (int n){
            if(n==1 || n==0){
                return n;
            }

            return fibo(n-1) + fibo(n-2);
        }
//______________________________________ tail problem _________________________________________        
        int tailprob (int n){
            if(n==1 || n==0){
                return 1;
            }

            return tailprob(n-1) + tailprob(n-2);
        }
//______________________________________ friend pair problem _________________________________________   
        int friendPair (int n){
            if(n==1 || n==0){
                return 1;
            }
    //if only one friend is prasent that n-1 or more then two friend one friend is single prasent 
            return friendPair(n-1) + (n-1)*friendPair(n-2);  
        }

//______________________________________ x to the power n  _________________________________________  
        int pow(int x ,int n){
            if(n==0){
                return 1;
            }
            int halfPow = pow(x , n/2);
            if(n%2 == 0){
                cout<< "even ";
                return halfPow * halfPow;
            }
            else{
                cout<< "odd ";
                return x * halfPow * halfPow; // pow is odd then again multiply it to value
            }
        }
//______________________________________ Array is Sorted  _________________________________________  
        bool Sorted(int arr[],int n, int i){
            if(i == (n-1)){
                return true;
            }
            if(arr[i] > arr[i+1]){
                return false;
            }
            return Sorted(arr ,n , i+1);
        }
//___________________________________ 50 pow(n,x) ___________________________________
    double myPow(double x, int n) {
        double product = 1;
        long long N = n;
        if(x == 0) return 0;
        if(n == 0 || x == 1) return 1;
        if(N < 0){
                x = 1 / x;
                N = -N;
        }
        while(N > 0){
            if(N%2 == 1){
                product *= x;
                N = N-1;
            }
            x*=x;
            N/=2;
        }
        
        return product;
    }

        int main(){
        cout <<" Enter Your number :   ";
        int n;
        cin>>n;

        int arr[] ={ 2,4,5,6,7,8};
        int size = sizeof(arr) / sizeof(arr[0]);
         if(Sorted(arr , size , 0)){
            cout << "array is sorted \n";
         }
         else{
            cout << "array is not sorted \n";
         }
          cout<<"2^"<< n << " = "<< pow( 2 ,n);
        }