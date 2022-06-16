// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int ele = nums[0], count = 1;
        
//         for(int i = 1; i < nums.size(); i++){
            
//             if(count == 0){
//                 count++;
//                 ele = nums[i];
//             }else if(nums[i] == ele){
//                 count++;
//             }else{
//                 count--;
//             }
            
//         }
        
//         return ele;
//     }
// };