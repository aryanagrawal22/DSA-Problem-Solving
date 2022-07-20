class Solution {
public:
    vector<int> partitionLabels(string s) {
        //Make a map of last found loc of the characters
        unordered_map<char, int> last;
        for(int i = 0; i<s.length(); i++){
            last[s[i]] = i;
        }
        
        //Iterate over the stirng and if the last found char index is greater than older found last char index then update it to newly found last found char index
        vector<int> ans;
        int maxDiv = 0, lastDiv = -1;
        for(int i = 0; i<s.length(); i++){
            maxDiv = max(maxDiv, last[s[i]]);
            
            //If the i reaches the maxDiv then divide the stirng from there by making it = lastDiv
            if(maxDiv==i){
                ans.push_back(maxDiv-lastDiv);
                lastDiv = maxDiv;
            }
        }
        return ans;
    }
};