class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, bool> um;
        for(int i = 0; i<nums.size(); i++){
            //If i greater than k then set the i-k-1 element of nums to false in map
            if(i>k) um[nums[i-k-1]]=false;
            //If it exist in map then return true
            if(um[nums[i]]) return true;
            //Set the map true for current value
            um[nums[i]] = true;
        }
        //Return false if no duplicates found
        return false;
    }
};