#include<iostream>
using namespace std;

void BinaryToDecimal(int bit){
    int n = bit;
    int dec = 0;
    int pow = 1; // 2^0
     while (n >0){
        int lastdig = n%10;
        dec += lastdig*pow;
        pow *= 2;
        n = n/10;
     }
     cout<<"decimal "<<dec;
}

void DecimalToBinary(int number){
    int n = number;
    int pow = 1; //10^0
    int bin = 0;
    while (n>0){
        int rem = n%2; //2 se divide karke remainder dekhte hai     4/2 = 0
        bin += rem*pow; // 0 = 0*1 = 0+0 = 0
        n = n/2;        // let n=4 = 4/2 = 2
        pow *= 10;      // 1*10 = 10
    }
    cout<<"Binary number of "<<number<< " is- "<<bin;
}
int main(){
    int n;
    // cout<<"Enter a bit:-";
    cout<<"Enter a decimal:-";
    cin>>n;
    // BinaryToDecimal(n);
    DecimalToBinary(n);
    return 0;
}