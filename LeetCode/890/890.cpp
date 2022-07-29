class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto word: words){
            if(word.length()!=pattern.length()) break;
            unordered_map<char, char> um;
            unordered_map<char, char> um2;
            bool hasPattern = true;
            for(int i = 0; i<pattern.length(); i++){
                if(!um[pattern[i]] && !um2[word[i]]) {
                    um[pattern[i]] = word[i];
                    um2[word[i]] = pattern[i];
                }
                if(um[pattern[i]] != word[i] || um2[word[i]] != pattern[i]) {
                    hasPattern = false;
                    break;
                }
            }
            if(hasPattern) ans.push_back(word);
        }
        return ans;
    }
};