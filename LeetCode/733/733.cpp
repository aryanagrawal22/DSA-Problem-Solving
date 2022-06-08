// class Solution {
// public:
    
//     void flood(vector<vector<int>>& image, int color, int newColor, int sr, int sc){
        
//         if (sr < 0 || sc < 0 ||  sr >= image.size() || sc >= image[0].size() || image[sr][sc] != color) {
//             return;
//         }
        
//         image[sr][sc] = newColor;
        
//         flood(image, color, newColor, sr - 1, sc );
//         flood(image, color, newColor, sr + 1, sc );
//         flood(image, color, newColor, sr, sc - 1);
//         flood(image, color, newColor, sr, sc + 1);
        
//         return;
    
//     }
    
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//         if (image[sr][sc] == newColor) return image;
//         int oldColor = image[sr][sc];
//         flood(image, oldColor, newColor, sr, sc);
//         return image;
//     }
// };