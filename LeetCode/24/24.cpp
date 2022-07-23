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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* node = head, *prev = NULL;
        head = node->next;
        while(node && node->next){
            if(prev) prev->next = node->next;
            ListNode* temp = node->next->next;
            node->next->next = node;
            node->next = temp;
            prev = node;
            node = temp;
        }
        return head;
    }
};