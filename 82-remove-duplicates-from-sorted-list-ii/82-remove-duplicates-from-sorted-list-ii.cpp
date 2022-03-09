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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* thead = new ListNode(-101, head);
        ListNode *prev = thead, *cur = head;
        
        while(cur && cur->next) {
            if(cur->val != cur->next->val) {
                prev = cur;
                cur = cur->next;
            } else {
                while(cur && cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                if(cur) {
                    prev->next = cur->next;
                    cur = cur->next;
                } else {
                    prev->next = cur;
                }
            }
        }
        
        return thead->next;
    }
};