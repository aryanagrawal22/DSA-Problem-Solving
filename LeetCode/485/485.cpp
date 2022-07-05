class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1s = 0, curr1s = 0;
        for(int num: nums){
            if(!num) curr1s = 0;
            else max1s = max(max1s, ++curr1s);
        }
        return max1s;
    }
};