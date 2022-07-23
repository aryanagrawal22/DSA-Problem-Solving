/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> s;
        ListNode *node = head;
        
        while(node) {
            ans.push_back(node->val);
            node = node->next;
        }
        
        for(int i=ans.size()-1; i>=0; i--) {
            while(!s.empty() && s.top()<=ans[i]){
                s.pop();
            }
            int temp = ans[i];
            ans[i] = s.empty()?0:s.top();
            s.push(temp);
        }
        return ans;
    }
};