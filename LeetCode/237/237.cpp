/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        //Cannot delete the node without the head, thus just shif the values of next node to one before
        //Delete last node to avoid duplicacy
        while(node->next->next!=NULL){
            node->val = node->next->val;
            node = node->next;
        }
        
        node->val = node->next->val;
        node->next = NULL;
        
        return;
        
    }
};