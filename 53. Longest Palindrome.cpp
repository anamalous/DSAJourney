#include <string>
#include <iostream>
#include <vector>

using namespace std;

int longestPalindrome(string s) {
    vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,0));
    int m=0;
    dp[s.size()][s.size()]=1;
    for(int i=0;i<s.size();i++){
        dp[i][i]=1;
        if(s[i]==s[i+1])
            dp[i][i+1]=2;
        m=max(max(dp[i][i],m),dp[i][i+1]);
    }
    for(int j=2;j<=s.size();j++)
        for(int i=0;i<=s.size()-j;i++){
            if(s[i]==s[i+j])
                dp[i][i+j]=dp[i+1][i+j-1]+2;
            m=max(m,dp[i][i+j]);
        }
    for(auto i:dp){
        for(int j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return m;
}

int main(){
    cout<<longestPalindrome("forgeeksskeegror");
}