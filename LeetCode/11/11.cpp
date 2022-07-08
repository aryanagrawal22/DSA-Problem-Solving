class Solution {
public:
    int maxArea(vector<int>& height) {

        int start = 0, end = height.size() - 1, area = 0;
        
        //Start from 0th index and nth (last) index and keep checking for higher height of the smaller side by making either start++ or end-- and calculate area for each if greater
        while(start<end){
            area = max(area, (end - start)*(min(height[end], height[start])));
            if(height[start]>height[end]) end--;
            else start++;
        }
        return area;
    }
};