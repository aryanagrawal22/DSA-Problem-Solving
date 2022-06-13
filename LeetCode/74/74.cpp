// class Solution {
// public:
    
//     int findRow(vector<vector<int>>& matrix, int target){
        
//         int r = matrix.size() - 1, l = 0, m;
//         int n = matrix[0].size() - 1;
//         while(l <= r){
            
//             m = l + (r - l)/2;
            
//             if(matrix[m][0]>target){
//                 r = m - 1;
//             }else if(matrix[m][0]<target){
//                 l = m;
//                 if(matrix[m][n]>=target) return m;
//                 else l = m+1;
//             }else{
//                 return m;
//             }
//         }
        
//         return m;
//     }
    
//     bool findEle(vector<int>& arr, int target){
        
//         int r = arr.size() - 1, l = 0, m;
        
//         while(l <= r){
        
//             m = l + (r - l)/2;
            
//             if(arr[m]>target){
//                 r = m - 1;
//             }else if(arr[m]<target){
//                 l = m + 1;
//             }else{
//                 return true;
//             }
//         }
        
//         return false;
//     }
    
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         // Binary Search for row
//         int row = findRow(matrix, target);
        
//         // Binart Search for element
//         bool found = findEle(matrix[row], target);
    
//         return found;
//     }
// };