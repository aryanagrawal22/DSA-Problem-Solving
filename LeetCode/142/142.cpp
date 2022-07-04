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
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head, *fast = head;
        
        //Kepp the loop running until fast == slow where; slow is next node; fast is next of next node
        //If NULL encountered by fast then return NULL ie loop not present
        do{
            
            if(fast == NULL || fast->next == NULL) return NULL;
            
            slow = slow->next;
            fast = fast->next->next;
            
        }while(slow!=fast);
        
        //Set fast to head again and now move fast and slow by one next node each time till they meet
        fast = head;
        
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        //Return the node where the the pointers meet
        return slow;
        
    }
};