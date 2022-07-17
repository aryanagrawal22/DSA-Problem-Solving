class Solution {
public:
    int mod = pow(10,9) * 2;
    int helper(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp){
        if(m<0 || n<0 || grid[m][n]==1) return 0;
        if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n] % mod;
        dp[m][n] = helper(grid, m-1, n, dp) % mod + helper(grid, m, n-1, dp) % mod;
        return dp[m][n] % mod;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(grid, m-1, n-1, dp);
    }
};