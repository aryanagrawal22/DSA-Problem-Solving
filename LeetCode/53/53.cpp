class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0, maxTillNow = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            curMax = max(nums[i], curMax + nums[i]),
            maxTillNow = max(maxTillNow, curMax);
        }
        return maxTillNow;
    }
};