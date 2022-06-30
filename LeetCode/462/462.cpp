class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums.size()/2;
        
        int index = 0, steps = 0;
        while(index < nums.size()){
            steps += abs(nums[median] - nums[index]);
            index++;
        }
        return steps;
    }
};