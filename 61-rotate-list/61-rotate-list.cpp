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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *newHead, *ptr, *last;
        if(k == 0) return head;
        
        newHead = head;  
        ptr = head;      
        
        // Count number of nodes
        int n = 0;
        while(ptr != NULL) {
            n++;
            last = ptr;
            ptr = ptr->next;
        }
        if(n == 0) return head;
        
        int rotate = n - k%n;
        if(rotate == 0) return newHead;
        
        while(--rotate) {
            newHead = newHead->next;
        }
        
        last->next = head;
        head = newHead->next;
        newHead->next = NULL;
        
        return head;
    }
};