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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        stack<int> s2;
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int size = s1.size()>s2.size()?s1.size():s2.size();
        
        ListNode *next = NULL;
        int carry = 0;
        for(int i = 0; i<size; i++){
            int num = 0;
            if(!s1.empty()) {
                num += s1.top();
                s1.pop();
            }
            if(!s2.empty()) {
                num += s2.top();
                s2.pop();
            }
            
            ListNode* head = new ListNode((num+carry)%10);
            head->next = next;
            next = head;
            carry = num+carry>9?1:0;
        }
        
        if(carry){
            ListNode* head = new ListNode(1);
            head->next = next;
            next = head;
        }
        
        return next;
    }
};