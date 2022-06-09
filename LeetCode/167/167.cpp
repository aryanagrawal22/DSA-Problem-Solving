// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int ptr1 = 0;
//         int ptr2 = numbers.size() - 1;
        
//         while(ptr1<ptr2){
//             if(numbers[ptr1]+numbers[ptr2]<target) ptr1++;
//             else if(numbers[ptr1]+numbers[ptr2]>target) ptr2--;
//             else break;
//         }
        
//         vector<int> arr;
//         arr.push_back(ptr1+1);
//         arr.push_back(ptr2+1);
        
//         return arr;
//     }
// };
