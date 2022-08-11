class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++) sum += nums[i];
        int left = 0, right = 0;
        for(int i = 0; i<nums.size(); i++){
            left+=nums[i];
            right=sum-left;
            //Left element is always smaller than current array in sorted order and when we make a prefix sum array then it is a sorted array
            ans.push_back(nums[i]*(i+1)-left+right-nums[i]*(nums.size()-1-i));
        }
        return ans;
    }
};