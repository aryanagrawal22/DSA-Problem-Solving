// class Solution {
// public:
    
//     map<string, int> map;
    
//     int answer(vector<vector<int>>& arr, int j , int i){
        
//         if (j >= arr.size())
//                 return 0;
//         string key = to_string(j) + "|" + to_string(i);
//             if (map.find(key)==map.end()){
//                 map.insert({key, min(answer(arr, j + 1, i), answer(arr, j + 1, i + 1)) + arr[j][i]});
//             }
//             return map[key];
//     }
    
//     int minimumTotal(vector<vector<int>>& triangle) {
        
//         if(triangle.size()==1) return triangle[0][0];
        
//         int ans = answer(triangle, 0, 0);
        
//         return ans;
//     }
// };