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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode *prev = NULL, *cur = head, *next = cur->next; 
        
        while(cur) {
            cur->next = prev;
            prev = cur;
            cur = next;
            if(cur) next = cur->next;
        }
        return prev;
    }
};


/**
a -> b -> NULL

in B: set a -> next to b -> next

**/