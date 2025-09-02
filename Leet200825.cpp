//all 1 square sub-matrices
#include <vector>
#include <iostream>

using std::vector;

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size(); 
    int ans = 0;
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {//for first row or column, values are 0 if 0 element and 1 if 1 itself 
                dp[i][j] = matrix[i][j];
            } else if (matrix[i][j] == 1) {
                dp[i][j] = std::min(std::min(dp[i - 1][j], dp[i][j - 1]), std::min(100,dp[i - 1][j - 1])) + 1;
            }
            ans += dp[i][j];
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> n={{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    std::cout<<countSquares(n);
}