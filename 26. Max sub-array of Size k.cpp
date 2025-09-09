#include <vector>
#include <iostream>

using std::vector;

int maxSubArray(vector<int> nums, int k){
    if(nums.size()<k)
        return 0;
    int r=0,max=0,curr=0;
    while(r<k){
        curr+=nums[r];
        r++;
    };
    max=curr;
    while(r<nums.size()){
        std::cout<<curr<<" ";
        curr-=nums[r-k];
        curr+=nums[r];r++;
        max=std::max(curr,max);
    }
    return max;
}

int main(){
    std::cout<<maxSubArray({1, 2, 3, 1, 4, 5, 2, 3, 6},3);
}