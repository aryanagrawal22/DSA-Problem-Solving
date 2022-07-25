class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        stack<int> rev;
        vector<int> ans;
        for (int i = 0; i<asteroids.size(); i++){
            if(asteroids[i]>0) s.push(asteroids[i]);
            else{
                while(!s.empty() && abs(asteroids[i])>s.top()) s.pop();
                
                if(s.empty()) ans.push_back(asteroids[i]);
                
                if(!s.empty() && abs(asteroids[i])==s.top()) {
                    s.pop();
                }
                
            }
        }
        
        while(!s.empty()){
            rev.push(s.top());
            s.pop();
        }
        
        while(!rev.empty()){
            ans.push_back(rev.top());
            rev.pop();
        }
        
        return ans;
    }
};