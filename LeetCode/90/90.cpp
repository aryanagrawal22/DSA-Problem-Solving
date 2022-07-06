class Solution {
public:
    
    void recurssion(set<vector<int>> &set, vector<int> nums, vector<int> curr, int index){
        
        //If index/level of recursion is equal to nums array length then push the curr added elements to set
        if(nums.size() == index) {
            set.insert(curr);
            return;
        }
        
        //Recurse for not adding the element i to the array
        recurssion(set, nums, curr, index+1);
        
        //Recurse for adding the element i to the array
        curr.push_back(nums[index]);
        recurssion(set, nums, curr, index+1);
        
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        //Make a set of array, so that no duplicates can be created
        set<vector<int>> set;
        
        //At the start create an empty array which keeps on adding elements on recurssion
        vector<int> subset = {};
        sort(nums.begin(), nums.end());
        
        recurssion(set, nums, subset, 0);
        
        //Push the array from set to matrix;
        vector<vector<int>> ans;
        for(auto i : set){
            ans.push_back(i);
        }
        return ans;
    }
};