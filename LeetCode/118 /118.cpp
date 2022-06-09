// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
        
//         vector<vector<int>> arr;
//         vector<int> prev;
        
//         arr.push_back({1});
//         if(numRows==1) return arr;
//         arr.push_back({1, 1});
//         if(numRows==2) return arr;
//         prev = {1, 1};
        
//         for(int i = 3; i<=numRows; i++){
//             vector <int> curr;
//             for(int j=0; j<i; j++){
//                 if(j==0) curr.push_back(1);
//                 else if(j==i-1) curr.push_back(1);
//                 else {
//                     curr.push_back(prev[j-1]+prev[j]);
//                 }
//             }
//             arr.push_back(curr);
//             prev = curr;
//         }
        
//         return arr;
//     }
// };