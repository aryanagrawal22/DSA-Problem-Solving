class Solution {
public:
    
    //Memolization
    int recurse(int n, vector<int> &memo){
        if(n==0) return 1;
        else if(n<0) return 0;
        else if(memo[n]!=-1) return memo[n];
        
        memo[n] = recurse(n-1, memo) + recurse(n-2, memo);
        
        return memo[n];
        
    }
    
    int climbStairs(int n) {
        vector<int> memo(n+1, -1);
        int ans = recurse(n, memo);
        return ans;
    }
};