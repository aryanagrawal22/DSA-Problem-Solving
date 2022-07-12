class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        
        for(int i = 1; i<strs.size(); i++){
            
            if(ans=="") return ans;
            string tempAns = "";
            int j=0, k=0;
            while(j < min(ans.length(), strs[i].length())){
                
                if(ans[j]==(strs[i])[j]) {
                    tempAns += ans[j];
                    j++;
                }else{
                    break;
                }
            }
            ans = tempAns;
            
        }
        
        return ans;
        
    }
};