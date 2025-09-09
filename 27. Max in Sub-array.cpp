#include <vector>
#include <iostream>

using std::vector;

vector<int> maxinSub(vector<int> nums, int k){
    int r=0,max=0;
    while(r<k){
        max=std::max(max,nums[r]);
        r++;
    }
    while(r<nums.size()){
    }
}