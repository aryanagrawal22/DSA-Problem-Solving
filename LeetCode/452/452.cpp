class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), [](auto const &a, auto const &b) {
            return a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]);
        });
        
        int start = points[0][0], end = points[0][1], ans = 0;
        
        for (int i = 1; i<points.size(); i++){
            if(points[i][0] <= end && points[i][1] <= end){
                start = points[i][0];
                end = points[i][1];
            }else if(points[i][0] <= end && points[i][1] > end){
                start = points[i][0];
            }else{
                ans++;
                start = points[i][0];
                end = points[i][1];
            }
        }
        return ans+1;
    }
};