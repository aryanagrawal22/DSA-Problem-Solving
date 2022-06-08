// class Solution {
// public:
//     string reverseWords(string s) {
//         stack<string> stack;
//         string temp = "";
//         for(int i = 0; i<s.length(); i++){
            
//             if(s[i]==' '){
//                 if(temp!="")stack.push(temp);
//                 temp="";
//             }else{
//                 temp+=s[i];
//             }
            
//         }
//         stack.push(temp);
        
//         string ans = "";
//         while(!stack.empty()){
//             temp=stack.top();
//             ans+=temp;
//             stack.pop();
//             if(!stack.empty() && temp!="") ans+=" ";
//         }
//         return ans;
        
//     }
// };