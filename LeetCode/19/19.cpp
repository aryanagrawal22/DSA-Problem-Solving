//*** Best solution of slow fast pointer ***\\

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode *fast = head, *slow = head;
//         for (int i = 0; i < n; i++) fast = fast->next;
//         if (!fast) return head->next;
//         while (fast->next) fast = fast->next, slow = slow->next;
//         slow->next = slow->next->next;
//         return head;
//     }
// };


// -----------------------------------------------------------------------------------------\\

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
    
    ListNode* recurse(ListNode* node, ListNode* prev, int &n){
        
        if(node==NULL) return node;
        recurse(node->next, node, n);
        n--;
        if(n==0 && prev != NULL) {
            prev->next = node->next;
        }
        else if(n==0 && prev == NULL) return node->next;
        return node;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = recurse(head, NULL, n);
        return node;
    }
};