    #include <iostream>
    #include <string>
    using namespace std;
//________________________________________________ pow x, n ______________________________________
    int pow(int x ,int n){
        if ( n==0){
            return 1;
        }
        int halfPow = pow(x , n/2);
        if(n%2 == 0){
        cout<<"even";
        return halfPow*halfPow;
        }
        else{
            cout<<"odd";
            return x * halfPow *halfPow;
        }
    }

//________________________________________________ duplicat string ______________________________________
void dupString( string str ,string ans , int i , bool map[26]){
    if(i == str.size()){
        cout<<"ans : "<< ans <<endl;
        return;
    }
    char ch  = str[i];
    int mapidx  = (int)(ch - 'A');
    if(map[mapidx]){
        dupString(str , ans , i+1 , map);
    }
    else{
        map[mapidx] = true;
         dupString(str , ans + str[i] , i+1 , map);
    }
}

//________________________________________________ Tail problem ______________________________________
    int tailProblem ( int n){
        if(n==0 || n==1){
            return 1;
        }
        return tailProblem(n-1) + tailProblem(n-2);
    }
//________________________________________________ friend pair ______________________________________
    int friendpair( int n){
        if(n==0 || n==1){
            return 1;
        }
        return friendpair(n-1) + (n-1)*friendpair(n-2);
    }
    int main(){
        // int x = 2 , n = 7;
        // cout<<pow(x , n);
        // cout<<tailProblem(4)<<" way to fill all tail\n";
        // cout<<friendpair(4)<<" 'way to made a pair of all friend'\n";
        string orignal = "OMPRAKASH";
        string ans = "";    //empty string 
        bool map[26] = {false}; // it is 26 alphabate that store in array and each point a false val 
        dupString( orignal , ans , 0 , map);
    return 0;
    }