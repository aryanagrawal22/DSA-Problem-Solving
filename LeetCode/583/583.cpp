// class Solution {
// public:
//     int helper(string word1, string word2,int m,int n,vector<vector<int>> &dp)
//     {
//         if(m==0 or n==0)
//             return 0;
        
//         if(dp[m][n] != -1)
//             return dp[m][n];
        
//         if(word1[m-1] == word2[n-1])
//             return dp[m][n] = 1+helper(word1,word2,m-1,n-1,dp);
        
//         else
//             return dp[m][n] = max(helper(word1,word2,m-1,n,dp),helper(word1,word2,m,n-1,dp));
//     }
    
//     int minDistance(string word1, string word2) 
//     {
//         int m = word1.size();
//         int n = word2.size();
//         vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
//         int lcs = helper(word1,word2,m,n,dp);
//         return m+n-(2*lcs);
//     }
// };