class Solution {
public:
    vector<int> dp;
    
    int helper(vector<int> days, vector<int> costs, int i){
        if(i>=days.size()) return 0;
        if(dp[i]) return dp[i];
        
        int dayCost = costs[0] + helper(days, costs, i+1);
        int currDay = days[i];
        
        int k;
        for(k = i ; k<days.size() and days[k]<days[i]+7 ; k++);
        int weekCost = costs[1] + helper(days, costs, k);
        
        for(k = i ; k<days.size() and days[k]<days[i]+30 ; k++);
        int monthCost = costs[2] + helper(days, costs, k);
        
        return dp[i] = min({dayCost, weekCost, monthCost});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(367);
        return helper(days, costs, 0);
    }
};