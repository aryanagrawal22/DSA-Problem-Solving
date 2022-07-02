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
    
    bool helper(ListNode* &top, ListNode* &tail){
        
        //Return from NULL
        if(!tail) return true;
        
        //Get previous ans of previous checks
        bool ans1 = helper(top, tail->next);
        
        //Compare top val and tail val
        bool ans2 = top->val==tail->val?true:false;
        
        //Make top to next node
        top = top->next;
        
        //If anyone of the ans is false then keep return false
        return (ans1 && ans2);
    }
    
    bool isPalindrome(ListNode* &head) {
        bool ans = helper(head, head);
        return ans;
    }
};