class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> um;
        for(int i = 0; i<magazine.size(); i++){
            um[magazine[i]] += 1;
        }
        
        for(int i = 0; i<ransomNote.size(); i++){
            if(um[ransomNote[i]]){
                um[ransomNote[i]] -= 1;
            }else{
                return false;
            }
        }
        
        return true;
    }
};