// Job sequencing
// maximize the total profit if only one job can be scheduled at a time
    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
    bool compare(pair<int,int>p1,pair<int,int>p2){
        return p1.second > p2.second;
    }
    int maxProfit(vector<pair<int ,int>>job){
        int n = job.size();

        sort(job.begin(),job.end(),compare);
         // first->deadline ,second->profit
        int profit = job[0].second;    
        int sefedeadline = 1;

        for(int i=1; i<n; i++){
            if(job[i].first >= sefedeadline){
                profit += job[i].second;  // profit is add in curr profit 
                sefedeadline++;  // deadline is + 1
            }
        }
        cout<<"maximum profit of job = "<<profit<<endl;
        return profit;
    }
    int main(){
        vector<pair<int,int>>job( 4 ,make_pair(0,0));
        job[0] = make_pair(1 ,20);
        job[1] = make_pair(1 ,10);
        job[2] = make_pair(4 ,40);
        job[3] = make_pair(1 ,30);

        maxProfit(job);
        return 0;
    }
// minor style fix
