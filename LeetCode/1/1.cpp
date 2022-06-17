class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int i = 0;
        int numberToFind = 0;
	    
        for (; i < nums.size(); i++) {
		    
            //Find number in HashMap == TotalSum - currNum which is already saved
            numberToFind = target - nums[i];

            //If Found then break
    		if (hash.find(numberToFind) != hash.end()) break;
    		
            //If loop still up then save the curr no. to HashMap
            hash[nums[i]] = i;
	    
        }
        
        //When loop breaks then save the value of numberToFind from HashMap (index 1) and i when the loop broke (index 2) 
        vector<int> result {hash[numberToFind], i};
	    return result;
    }
};