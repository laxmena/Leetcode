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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head = ListNode(0);
        ListNode* ptr = &head;
        while(list1 && list2) {
            ListNode* node;
            if(list1->val < list2->val) {
                node = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                node = new ListNode(list2->val);
                list2 = list2->next;
            } 
            ptr->next = node;
            ptr = node;
        }
        while(list1) {
            ListNode* node = new ListNode(list1->val);
            list1 = list1->next;
            ptr->next = node; 
            ptr = node;
        }
        while(list2) {
            ListNode* node = new ListNode(list2->val);
            list2 = list2->next;
            ptr->next = node;
            ptr = node;
        }
        return head.next;
    }
};