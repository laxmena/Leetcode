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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *result;
        result = head;
        int sum, carry = 0;
        
        while(l1 && l2) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* s = new ListNode(sum);
            result->next = s;
            result = result->next;
            l1 = l1->next; l2 = l2->next;
        }
        ListNode* l = l1? l1: l2;
        while(l) {
            sum = l->val + carry;
            carry = sum/10;
            sum %= 10;
            ListNode* s = new ListNode(sum);
            result->next = s;
            result = result->next;
            l = l->next;
        }
        if(carry) {
            ListNode* s = new ListNode(carry);
            result->next = s;
        }
        return head->next;
    }
};