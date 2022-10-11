class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        int maxFromRight[n], minFromLeft[n];
        maxFromRight[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            maxFromRight[i] = max(nums[i], maxFromRight[i+1]);
        }
        
        minFromLeft[0] = nums[0];
        for(int i=1; i<n; i++){
            minFromLeft[i] = min(nums[i], minFromLeft[i-1]);
        }
        
        for(int i=0; i<n; i++){
            // If you find a nums[i] such that minFromLeft[i]<nums[i]<maxFromRight[i] 
			// means there exists an increasing triplet
			if(minFromLeft[i]<nums[i] &&maxFromRight[i]>nums[i]) 
					return true;
        }
        return false;
    }
};