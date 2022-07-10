class Solution {
public:
    void helper(vector<vector<char>>& grid, int i, int j){
        
        //If out of bound, water region or already visited then rerturn
        if(j<0 || i<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0' || grid[i][j]=='2') return;
        
        //If the node is 1 then make it 1, to denote that it has been visited
        grid[i][j] = '2';
        
        //Traverse the adjecent nodes for more 1's
        helper(grid, i+1, j);
        helper(grid, i, j-1);
        helper(grid, i-1, j);
        helper(grid, i, j+1);
        
        return;
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        //Goto each node and if it is 1 then increment ans and send it to traverse the adjecent 1's
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    helper(grid, i, j);
                    ++ans;
                } 
            }
        }
        
        return ans;
    }
};