#include <iostream>
#include <vector>

using std::vector;

int count(vector<int> coins, int sum) {
    vector<int> sums(sum+1,0);
    sums[0]=1;
    for(int coin:coins){
        for(int i=coin;i<sum+1;i++){
            sums[i]+=sums[i-coin];
        }
    }
    return sums[sum];
}

int main(){
    std::cout<<count({2,5,3,6},10);
}