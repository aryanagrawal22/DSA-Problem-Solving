class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<string> ans(size(score));
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i<score.size(); i++) pq.push(make_pair(score[i], i));
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            if(pq.size()==score.size()-1) ans[top.second] = "Gold Medal";
            else if(pq.size()==score.size()-2) ans[top.second] = "Silver Medal";
            else if(pq.size()==score.size()-3) ans[top.second] = "Bronze Medal";
            else ans[top.second] = to_string(score.size() - pq.size());
        }
        
        return ans;
    }
};