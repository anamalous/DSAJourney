#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;

int longestCommonSubstr(string s1, string s2) {
    vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
    
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
        }
    }
    for(vector<int> i:dp){
        for(int j:i)
            std::cout<<j<<" ";
        std::cout<<std::endl;
    }
    return dp[s1.size()][s2.size()];
}

int main(){
    std::cout<<longestCommonSubstr("ABCDGH","ACDGHR");
}