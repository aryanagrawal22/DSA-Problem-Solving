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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        
        ListNode* end = head, *node = head;
        while(end->next) end = end->next;
        
        bool isOdd = false;
        ListNode* transfer = end, *prev = NULL;
        while(node!=end){
            if(isOdd){
                prev->next = node->next;
                transfer->next = node;
                transfer = transfer->next;
                transfer->next = NULL;
                node = prev->next;
            }else{
                prev = node;
                node = node->next;
            }
            isOdd = !isOdd;
        }
        
        if(isOdd){
            prev->next = node->next;
            transfer->next = node;
            transfer = transfer->next;
            transfer->next = NULL;
            node = prev->next;
        }
        
        return head;
    }
};