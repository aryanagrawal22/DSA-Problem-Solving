class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for (int i = 0; i<ops.size(); i++){
            if(ops[i]=="C"){
                s.pop();
            }else if(ops[i]=="D"){
                s.push(s.top()*2);
            }else if(ops[i]=="+"){
                int top = s.top();
                s.pop();
                int second = s.top();
                s.push(top);
                s.push(s.top()+second);
            }else{
                s.push(stoi(ops[i]));
            }
        }
        int sum = 0;
        while(!s.empty()) {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};