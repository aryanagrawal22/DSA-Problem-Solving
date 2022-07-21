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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *node = head, *before = NULL, *ahead = NULL, *leftNode, *rightNode;
        int i = 1;
        
        while(node!=NULL){
            if(i == left-1) before = node;
            if(i==left) leftNode = node;
            if(i==right) rightNode = node;
            if(i==right+1) ahead = node;
            node = node->next;
            i++;
        }
        
        rightNode->next = NULL;
        node = leftNode;
        
        if(leftNode == head) head = rightNode;
        
        ListNode *prev = NULL, *next = NULL;
        while(node!=NULL){
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        
        if(before) before->next = rightNode;
        leftNode->next = ahead;
        
        return head;
        
    }
};