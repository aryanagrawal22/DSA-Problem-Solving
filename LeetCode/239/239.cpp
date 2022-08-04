class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        //Doubly linked list to keep track of front and back elements storing indexs of the nums array
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            //If not empty and and front index is equal to i-k then pop front
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
            //While back index val is less than nums[i] keep popping to make it strictly decreasing 
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
            //Push the elemetn of back index if i is greater or equal to k-1
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};