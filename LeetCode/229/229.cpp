//Not the best solution can be further optimized to space complexity of O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
            map<int, int> um;
            vector<int> arr;
        
            for (int i =0; i<nums.size(); i++){
                um[nums[i]]++;
                if(um[nums[i]]==floor(nums.size()/3)+1){
                    arr.push_back(nums[i]);
                }
            }
            
            return arr;
    }
};