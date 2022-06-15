// class Solution {
// public:
//     int dp[101][101];
    
//     int uniquePaths(int m, int n) {
//         memset(dp, -1, sizeof(dp));
//         int ans = answer(0, 0, m, n);
//         return ans;
//     }
    
//     int answer(int curRow, int curCol, int m, int n){
//         if(curRow==m-1 && curCol == n-1) return 1;
        
//         if(curRow>=m || curCol>=n) return 0;
        
//         if(dp[curRow][curCol]!=-1) return dp[curRow][curCol];
//         else return dp[curRow][curCol] = answer(curRow+1, curCol, m, n) + answer(curRow, curCol+1, m, n);
//     }
// };