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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode *f = head, *s = head;
        
        do {
            f = f->next->next;
            s = s->next;
        } while(f && f->next && f != s);
        
        return f == s;
    }
};