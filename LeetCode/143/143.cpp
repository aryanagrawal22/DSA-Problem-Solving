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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* node = head;
        
        //Store the elements in a stack
        while(node!=NULL){
            s.push(node);
            node = node->next;
        }
        
        //Only pop half the elements from stack as we have to shift the end nodes(top half of stack) 
        int len = s.size()/2;
        
        node = head;
        for(int i = 0; i<len; i++){
            ListNode *temp = s.top();
            s.pop();
            temp->next = node->next;
            node->next = temp;
            node = node->next->next;
        }
        node->next = NULL;
    }
};