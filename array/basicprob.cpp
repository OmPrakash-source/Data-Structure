#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void isPrime(int n){
    if(n<=1) cout<<"Given number "<<n<<" is not prime \n";
    
    for (int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){ 
            cout<<"Given number "<<n<<" is not prime \n";
            return;
        }
    }
    cout<<"Given number "<< n <<" is prime \n";
}

bool isPalindrome(int n){
    int m = n;
    int rev = 0;
    while(m != 0){
        int digit = m%10;
        rev = rev * 10 + digit;
        m = m/10;
    }
    return n == rev;
}

// bool leap(int n){
//     if((n%4 == 0 && n%100 != 0) || n%400 == 0) return true;
//     return false;
// }
// int main(){
//     int n = 2021;
//     if(leap(n)){
//         cout<<"leap year";
//     }else{
//         cout<<"Not a leap year";
//     }
// }
//Divisible by 4 but not 100, or divisible by 400
int fact(int n){
    int sum = 1;
    for(int i=2;i<=n;i++){
        sum *= i;
    }
    return sum;
}
int reverseInt(int num){
    int n = num;
    int rev = 0;
    while(n > 0){
        int lastdig = n%10;
        rev = rev * 10 + lastdig;
        n /= 10;
    }
    return rev;
}
bool Armstrong(int num){
    int sum = 0;
    int n = num;
    int digit = 0;
    while(n > 0){
        digit += 1;
        n /= 10;
    }
    n = num;
    while(n > 0){
        int lastdig = n%10;
        int multi = 1;
        for(int i=0; i<digit; i++){
            multi *= lastdig;
        }
        sum += multi;
        n /= 10;
    }
    return sum == num;
}

void revec(vector<int>&nums){
    int i=0, j = nums.size()-1;
    while(i <= j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
}
int maxele(vector<int>nums){
    int maxi = INT16_MIN;
    for(int i : nums){
        if(maxi < i){
            maxi = i;
        }
    }
    return maxi;
}

void avg_sum(int num){
    int digit = 0;
    int temp = num;
    while(temp > 0){
        digit++;
        temp/=10;
    }
    temp = num;
    int sum = 0;
    while(temp > 0){
        sum += temp%10;
        temp /= 10;
    }
    cout<<"sum of digit is "<<sum<<" and avrage are "<<(double)sum/digit<<endl;
}

void rotate_right(vector<int>&nums,int k){
    int n = nums.size();
    k = k % n;
    if(n == 0) return; 
    if(k == 0) return;
    vector<int>temp;
    for (int i = n - k; i < n; i++){
        temp.push_back(nums[i]);
    }

    for(int i=n-k-1; i>=0; i--){
        nums[k+i] = nums[i];
    }
    for(int i=0; i<temp.size(); i++){
        nums[i] = temp[i];
    }
}

void rotate_right2(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return;

    k %= n;  // safe mod
    if (k == 0) return;

    vector<int> temp;
    temp.reserve(k);

    // copy last k elements
    for (int i = n - k; i < n; i++) {
        temp.push_back(nums[i]);
    }

    // shift remaining elements right by k
    for (int i = n - 1; i >= k; i--) {
        nums[i] = nums[i - k];
    }

    // place saved elements at front
    for (int i = 0; i < k; i++) {
        nums[i] = temp[i];
    }
    }
    void rev(string &s){
        int i = 0, j = s.length()-1;
        while(i < j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            j--;
            i++;
        }
    }
    int countvov(string s){
        int count = 0;
        for(char ch : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') count++;
        }
        return count;
    }
    int main(){
        string s;
        cout<<"enter string ";
        getline(cin,s);
        cout << countvov(s);
    }
// minor style fix
