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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        ListNode *p1 = head, *p2 = head;
        while(p2->next != NULL && p2->next->next != NULL) {
            p2 = p2->next->next;
            if(p2->next != NULL) p1 = p1->next;
        }
        
        p1->next = p1->next->next;
        return head;
    }
};

// 7
// 0 1 2 3 4 5 6
// 2 2 2 2 2 2 2
// 1 1 1 1
    
// 6
