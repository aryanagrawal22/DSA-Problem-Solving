class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](auto const &a, auto const &b) { 
            return a[0] > b[0] || (a[0] == b[0] && a[1]<b[1]);
        });
        vector<vector<int>> ans;
        for (auto person : people){
            ans.insert(ans.begin() + person[1], person);
        }
        return ans;
    }
};