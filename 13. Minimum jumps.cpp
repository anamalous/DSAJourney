#include <iostream>
#include <vector>

using std::vector;

int minJumps(vector<int>& arr) {
    vector<int> dp;
    dp.push_back(0); //steps to last index from last index
    for(int i=arr.size()-2;i>=0;i--){
        if(arr[i]>=arr.size()-i-1)
            dp.push_back(1); //enough step count to reach the end directly
        else{
            int minstep=arr.size();
            //iterate to all steps after this which can be reached
            for(int j=dp.size()-1;j>dp.size()-1-arr[i];j--){
                if(dp[j]<minstep&&dp[j]>0)
                    minstep=dp[j]; //update the minimum steps needed from current location
                if(minstep==1)
                    break;
            }
            if(minstep==arr.size())
                dp.push_back(-1);
            else
                dp.push_back(minstep+1);
        }
    }
    for(int i:dp)
        std::cout<<i<<" ";
    std::cout<<std::endl;
    return dp[dp.size()-1];
}

int main(){
    //vector<int> arr={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    //vector<int> arr={1, 4, 3, 2, 6, 7};
    vector<int> arr={0, 10, 20};
    //vector<int> arr={1,2,0,0,0};
    std::cout<<minJumps(arr);
}