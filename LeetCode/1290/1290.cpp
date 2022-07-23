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
    int helper(ListNode* node, int& sum){
        if(!node) return 0;
        int nodeNum = helper(node->next, sum);
        if(!nodeNum) {
            sum += node->val;
        }else{
            sum += pow(2, nodeNum) * node->val;
        }
        return nodeNum + 1;
    }
    
    int getDecimalValue(ListNode* head) {
        int sum = 0;
        helper(head, sum);
        return sum;
    }
};