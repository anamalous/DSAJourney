#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftmax=0,leftind=0;
        for(int i=0;i<height.size();i++){
            if(height[i]*i>=leftmax){
                leftmax=height[i]*i;
                leftind=i;
            }
        }
        int ctr=0,rightmax=0,rightind=0;  
        if(leftind!=height.size()-1){
            rightmax=height[height.size()-1];
            rightind=height.size()-1;
        }
        for(int i=height.size()-1;i>=0;i--){
            if(i==leftind){
                ctr++;
                continue;
            }
            if(height[i]*ctr>=rightmax){
                rightmax=height[i]*ctr;
                rightind=i;
            }
            ctr++;
        }
        std::cout<<leftind<<" "<<rightind;
        return std::abs(std::min(height[leftind],height[rightind])*(leftind-rightind));
    }
};