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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0, head);
        ListNode *fp = temp, *sp = temp;
        
        while(n--) fp = fp->next;
        while(fp) {
            fp = fp->next;
            if(fp == NULL) {
                sp->next = sp->next->next;            
            } else {
                sp = sp->next;                
            }
        }
        
        return temp->next;
    }
};