    #include<iostream>
    #include<vector>
    using namespace std;
    int maxActivitie(vector<int>start ,vector<int>end){
        // sort a end : is already done in question
        // count = 1 becouse Activitie A1 is already stored
        cout<<"selected A0\n";
        int count = 1;
        int currEnd = end[0];
        for (int i = 1; i<=end.size();i++){
            if(start[i]>=currEnd){         // . chack a non overlap is prasent 
            cout<<"selected A"<<i<<endl;
                count++;                   // . count ko 1++ karna hai
                currEnd = end[i];          // . currEnd me end[i] ki end value feed karna hai
            }
        }
        return count;
    }
    int main(){
        vector<int>start ={1,3,0,5,8,5};
        vector<int>end =  {2,4,6,7,9,9};
        cout<<" maximum activitie : "<<maxActivitie(start,end);
    }