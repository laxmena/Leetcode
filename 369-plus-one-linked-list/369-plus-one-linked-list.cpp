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
    int addOne(ListNode* node) {
        int carry = 0;
        if(node->next) carry = addOne(node->next);
        else carry = 1;
        
        if(carry) {
            node->val += 1;
            int rem = node->val / 10;
            node->val %= 10;
            return rem;            
        }
        return 0;
    }
    ListNode* plusOne(ListNode* head) {
        ListNode* temp = new ListNode(0, head);
        int rem = addOne(temp);
        return temp->val==1?temp:temp->next;
    }
};