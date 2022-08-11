class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 1;
        priority_queue <pair<int, int>> pq;
        for(int i = 0; i<nums.size(); i++) pq.push(make_pair(nums[i], i));
        ans *= (nums[pq.top().second]-1);
        pq.pop();
        return ans *= (nums[pq.top().second]-1);
    }
};