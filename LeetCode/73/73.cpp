// class Solution {
// public:
    
//     multimap<int, int> map;
    
//     void setZeroes(vector<vector<int>>& matrix) {
//         for(int j=0; j<matrix.size(); j++){
//             for(int i=0; i<matrix[0].size(); i++){
//                 if(matrix[j][i]==0) map.insert(pair<int, int>(j, i));
//             }
//         }
        
//         for(auto i=map.begin(); i!=map.end(); i++){
//             for(int y=0; y<matrix.size(); y++){
//                 matrix[y][i->second]=0;
//             }
            
//             for(int x=0; x<matrix[0].size(); x++){
//                 matrix[i->first][x]=0;
//             }
//         }
//     }
// };