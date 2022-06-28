class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // Make a set and save all the arr elements in the set
        set<int> set;
        int longest = 0;
        
        for (int i = 0; i<nums.size(); i++){
            set.insert(nums[i]);
        }
        
        //Iterate over the nums array now only if we don't find any previous element of curr element
        for (int i = 0; i<nums.size(); i++){
            if(!set.count(nums[i]-1)){
                int currNum = nums[i];
                int currStreak = 1;
                
                //Keep increasing currStreak till the next num is not found in the set
                while(set.count(currNum+1)){
                    currNum++;
                    currStreak++;
                }
                
                //Choose the largest value
                longest = max(longest, currStreak);
            }
        }
        
        return longest;
    }
};