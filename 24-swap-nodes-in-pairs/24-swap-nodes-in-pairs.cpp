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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = new ListNode(0, head);
        ListNode* p = temp, *p1;
        while(p->next && p->next->next) {
            // head -> 1 -> 2 -> 3
            // head -> 2 -> 3 | Store 1 ->(2)
            // head -> 2 -> 3 | Change 1 -> 3
            // head -> 2 -> 1 -> 3
            // Update head to 1
            p1 = p->next;
            p->next = p->next->next;
            p1->next = p->next->next;
            p->next->next = p1;
            p = p1;
        }
        return temp->next;
    }
};