//0 filled sub array
#include <iostream>
#include <vector>
#include <cmath>
using std::vector;

int zeroCount(vector<int> nums){
    int ctr=0,zeros=0;
    for(auto item:nums){
        if(item!=0){
            zeros+=(ctr*(ctr+1))/2;
            ctr=0;
        }
        else
            ctr++;
    }
    zeros+=(ctr*(ctr+1))/2;//for 0s at the end;
    return zeros;
}

int main(){
    vector<int> n={1,0,0,0,0,3,2,0,0,4,5,0};
    std::cout<<zeroCount(n);
}