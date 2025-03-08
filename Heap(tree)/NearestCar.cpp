#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// O(klogn + n)
class Car{
    public:
    int idx;
    int disSq;
    Car(int idx, int disSq){
        this->idx = idx;
        this->disSq = disSq;
    } 
    bool operator < (const Car &obj) const { // operator overloding 
        return this->disSq > obj.disSq; // min heap ( max heap < )
    }

};
void NearCar(vector<pair<int,int>>pos,int k){
    vector<Car> cars;

    for(int i=0; i<pos.size(); i++){ //O(n)
        int disSq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second); //(3*3) + (-1*-1)
        cars.push_back(Car(i,disSq)); // objet(idx,disSqare)
    }

    priority_queue<Car>pq(cars.begin(),cars.end()); // create a heap using(first,second) 

    for(int i=0; i<k; i++){ //O(k*logn)
        cout<< "car "<<pq.top().idx<<endl; //O(1)
        pq.pop();   // O(logn)
    }
}

int main(){
    vector<pair<int,int>>pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));

    int k = 2; // print no of k index
    NearCar(pos, k);
    return 0;
}
