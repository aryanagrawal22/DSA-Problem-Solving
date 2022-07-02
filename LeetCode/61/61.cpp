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
    
    ListNode* helper(ListNode* &head, ListNode* node, ListNode* prev, int &k){
        
        //If reached NULL then return;
        if(!node) return head;
        
        helper(head, node->next, node, k);
        
        //If it is at the last node and k exists then make the last element as first and prev as last of the LL
        if(node->next==NULL && k){
                node->next = head;
                head = node;
                prev->next = NULL;
                k--;
        }
        
        return head;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        //If head or next element is NULL then return head
        if(!head || !head->next) return head;
        int len = 1;
        ListNode* node = head;
        
        //Calc the length of the LL
        while(node->next){
            len++;
            node = node->next;
        }
        
        //If length < k then this makes it lesser than length
        k = k%len;
        
        //Send head, currNode, prevNode and k 
        ListNode* newHead = helper(head, head, NULL, k);
        return newHead;
    }
};