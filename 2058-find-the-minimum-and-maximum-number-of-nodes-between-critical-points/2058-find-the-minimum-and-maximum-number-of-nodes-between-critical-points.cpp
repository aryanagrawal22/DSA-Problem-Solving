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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *node = head->next, *prev = head;
        int i = 1;
        vector<int> index;
        while(node->next){
            if((prev->val<node->val && node->val>node->next->val) || (prev->val>node->val && node->val<node->next->val)) index.push_back(i);
            prev = node;
            node = node->next;
            i++;
        }
        if(index.size()<2) return {-1, -1};
        if(index.size()==2) return {index[1]-index[0], index[1]-index[0]};
        int minDist = INT_MAX;
        for(int i = 1; i<index.size(); i++){
            minDist = min(minDist, index[i]-index[i-1]);
        }
        return {minDist, index[index.size()-1]-index[0]};
    }
};