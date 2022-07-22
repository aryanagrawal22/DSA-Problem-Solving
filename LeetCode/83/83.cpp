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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *node = head->next, *prev = head;
        while(node!=NULL){
            if(node->val==prev->val){
                prev->next = node->next;
                node = node->next;
            }else{
                prev = prev->next;
                node = node->next;
            }
        }
        return head;
    }
};