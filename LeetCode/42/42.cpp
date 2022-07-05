class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> leftWall;
        vector<int> rightWall;
        
        int highest = 0;
        
        //Calculate the highest wall length from left
        for (int i = 0; i<height.size(); i++){
            if(height[i]>highest){
                leftWall.push_back(height[i]);
                highest = height[i];
            }else leftWall.push_back(highest);
        }
        
        highest = 0;
        
        //Calculate the highest wall length from right
        for (int i = height.size()-1; i>=0; i--){
            if(height[i]>highest){
                rightWall.push_back(height[i]);
                highest = height[i];
            }else rightWall.push_back(highest);
        }
        
        //Make it to orient it the correct way otherwise it is in reverse
        reverse(rightWall.begin(), rightWall.end());
        
        //Now the water level gets added if in +ve of the row when (min wall of left or right - heightOfRowWall)
        int waterBlocks = 0;
        for(int i = 0; i<height.size(); i++){
            int waterInRow = min(leftWall[i], rightWall[i]) - height[i];
            if(waterInRow>0) waterBlocks += waterInRow;
        }
        
        return waterBlocks;
    }
};