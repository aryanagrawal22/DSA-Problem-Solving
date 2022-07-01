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
    
    ListNode* helper(ListNode* l1, ListNode* l2, ListNode* prev, int carry){
        //If both NULL then return NULL
        if(!l1 && !l2) {
            
            //If carry still exist then make a new node of it
            if(carry) {
                ListNode* curr = new ListNode(carry);
                prev->next = curr;
            }
            return NULL;
        };
        
        // SUM = ptr1 + ptr2 + carry
        int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
        
        //If carry greater than 9 then make carry
        carry = sum>9 ? 1 : 0;
        ListNode* curr = new ListNode(sum%10);
        
        //Make prev connect with current and send curr as prev for next recursion
        if(prev) prev->next = curr;
        helper(l1?l1->next:NULL, l2?l2->next:NULL, curr, carry);
        
        return curr;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node = helper(l1, l2, NULL, 0);
        return node;
    }
};