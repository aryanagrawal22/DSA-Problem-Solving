class Solution {
public:
    
    void recurssion(vector<vector<int>>& ans, vector<int> arr, int sum, vector<int>& candidates, int target, int index){
        
        //if sum is target then add the arr to ans matrix
        if(sum == target){
            ans.push_back(arr);
            return;
        }
        
        if(index == candidates.size()) return;
        
        //If currSum is less than target then either send the index to next pos without adding anything
        //or keep the index same and keep adding the curr element
        if(sum < target)
        {            
            recurssion(ans, arr, sum, candidates, target, index+1);
            arr.push_back(candidates[index]);
            sum += candidates[index];
            recurssion(ans, arr, sum, candidates, target, index);
            
        //If currSum is equal or greater than target then keep the sum same and keep sending it to next element
        //until it reaches index == candidates.size() and returned
        } else {
            recurssion(ans, arr, sum, candidates, target, index+1);
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> arr = {};
        recurssion(ans, arr, 0, candidates, target, 0);
        return ans;
    }
};