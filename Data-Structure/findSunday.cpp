#include <iostream>
using namespace std;
int totalsunday(string day, int date){
    int startDay = 0;
    if(day == "mon") startDay = 1;
    else if (day == "tue") startDay = 2;
    else if (day == "wed") startDay = 3;
    else if (day == "thu") startDay = 4;
    else if (day == "fri") startDay = 5;
    else if (day == "sat") startDay = 6;
    else if (day == "sun") startDay = 7;
    int current = 0;
    int count = 0;
    for(int i=0 ;i<date; i++){
        current = (startDay + i) % 7;
        if(current  == 0) count++;
    }
    return count;
}
int main(){
    // cout<< "total sunday's "<<totalsunday("tue", 30);
    // int i=1;
    // cout<< i++ << " ";
    // cout<< ++i;

    // int a = 5;
    // cout << a-- << " " << --a;
int x = 0;
cout << (x++ && ++x);


}

// minor style fix
