class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   //XOR operator
       for(auto x:nums) ans^=x;
	   return ans;
    }
};