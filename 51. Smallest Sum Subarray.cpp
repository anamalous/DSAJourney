#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int smallestSumSubarr(vector<int> arr){
    int sum=0,m=0;
    for(int i:arr){
        sum=min(sum+i,i);
        m=min(m,sum);
    }
    return m;
}

int main(){
    cout<<smallestSumSubarr({3,-4,2,-3,-1,7,-5});
}