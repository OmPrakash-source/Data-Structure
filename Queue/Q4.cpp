    #include<iostream>
    #include<deque>
    using namespace std;
    int main(){
        deque<int>que;
        que.push_front(30);
        que.push_front(20);
        que.push_front(10);
        que.push_back(40);
        que.push_back(50);
        que.push_back(60);
        // accass to front of queue
        while(!que.empty()){
            cout<<que.front()<<" ";
            que.pop_front();
        }
        // accass to front of queue but ty that time queue is empty that it's not print a any value
        while(!que.empty()){
            cout<<que.back()<<" ";
            que.pop_back();
        }

        //push_front()
        //push_back()
        //pop_front()
        //pop_back()
        //front()
        //back()

        return 0;
    }