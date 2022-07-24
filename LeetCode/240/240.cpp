class Solution {
public:
    
    //Solution: like a binary search tree here the root is bottom-left block where top nodes are smaller and right nodes are bigger like in a BST. Following that logic we get the ans by comapring the target.
    //The T(O) = M+N where M is no. of cols and N is no. of rows
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = row-1,j =0;
        while(i>=0&&j<=col-1)
        {
            if(target>matrix[i][j])
            {
                j++;
            }
            else if(target<matrix[i][j])
            {
                i--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};