#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int knapSack(vector<int> val, vector<int> wt, int capacity) {
    vector<int> dp(capacity+1,0);
    for(int i=1;i<capacity+1;i++){
        for(int j=0;j<wt.size();j++){
            if(wt[j]>i)
                continue;
            dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
        }
    }    
    
    return dp[capacity];
}

int main(){
    cout<<knapSack({6,1,7,7},{1,3,4,5},8);
}