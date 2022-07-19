class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        vector<int> maxRow;
        vector<int> maxCol;
        
        for(int i = 0; i<grid.size(); i++){
            int rowEle = INT_MIN, colEle = INT_MIN;
            for(int j = 0; j<grid[0].size(); j++){
                rowEle = max(rowEle, grid[i][j]);
                colEle = max(colEle, grid[j][i]);
            }
            maxRow.push_back(rowEle);
            maxCol.push_back(colEle);
        }
        
        int maxTotSum = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                maxTotSum += min(maxRow[i], maxCol[j]) - grid[i][j];
            }
        }
        
        return maxTotSum;
    }
};