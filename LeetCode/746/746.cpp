class Solution {
public:
    int helper(vector<int>& cost, int i, vector<int>& dp){
        
        if(i<0) return 0;
        if(i==0) return cost[i];
        
        if(dp[i]==-1){
            dp[i] = cost[i] + min(helper(cost, i-1, dp), helper(cost, i-2, dp));
        }
        
        return dp[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(size(cost)+1, -1);
        int ans = min(helper(cost, cost.size()-2, dp), helper(cost, cost.size()-1, dp));
        return ans;
    }
};