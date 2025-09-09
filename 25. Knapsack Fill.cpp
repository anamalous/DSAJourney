#include <vector>
#include <iostream>

using std::vector;

int maxValue(vector<int> val,vector<int> wei,int knap){
    vector<int> dp(knap+1,0);
    dp[0]=0;//value of a 0 weight knapsack is 0
    for(int i=0;i<wei.size();i++){
        for(int j=knap;j>=wei[i];j--){//can only affect configurations above its own weight
            dp[j]=std::max(dp[j],val[i]+dp[j-wei[i]]);
        }
    }
    return dp[dp.size()-1];
}

int main(){
    std::cout<<maxValue({1,2,3},{4,5,1},4);
}