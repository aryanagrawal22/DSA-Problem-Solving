class Solution {
public:
    bool check(vector<vector<int>>& matrix, int i, int j, int val){
        if(i>=matrix.size() || j>=matrix[0].size()) return true;
        if(matrix[i][j]!=val) return false;
        return check(matrix, i+1, j+1, val);
    }
    
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); i++){
            if(!check(matrix, i, 0, matrix[i][0])) return false;
        }
        for(int i=0; i<matrix[0].size(); i++){
            if(!check(matrix, 0, i, matrix[0][i])) return false;
        }
        return true;
    }
};