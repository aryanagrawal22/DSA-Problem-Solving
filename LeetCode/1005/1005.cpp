class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        int index = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i<nums.size(); i++){
            if(!k) break;
            if(nums[i]<0){
                nums[i] = -nums[i];
                k--;
            }
        }
        
        sort(nums.begin(), nums.end());
        
        while(k){
            nums[0] = -nums[0];
            k--;
        }
        
        return accumulate(nums.begin(), nums.end(), 0);
    }
};