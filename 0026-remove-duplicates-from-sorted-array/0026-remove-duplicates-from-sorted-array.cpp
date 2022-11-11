class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //Initialize k to 1 as one element is definitely present
        int k = 1;
        
        //Loop throught the array and if curr and next element are same then save it at kth loc and then increase k
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i]!=nums[i+1]) {
                nums[k] = nums[i+1];
                k++;
            }
        }
        return k;    
    }
};