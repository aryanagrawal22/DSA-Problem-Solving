class Solution {
public:
    
    void recurssion(vector<vector<int>>& ans, vector<int> &arr, int target, vector<int>& candidates, int index){
        if(target == 0){
            ans.push_back(arr);
            return;
        }
        
        for(int i = index; i< candidates.size(); i++){
            if(candidates[i] > target) break; 
            if(i  > index && candidates[i] == candidates[i-1]) continue;
            arr.push_back(candidates[i]);
            recurssion(ans, arr, target - candidates[i], candidates, i + 1);
            arr.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> arr = {};
        vector<vector<int>> ans;
        recurssion(ans, arr, target, candidates, 0);
        return ans;
    }
};