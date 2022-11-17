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
        ListNode res(0);
        ListNode* ptr = &res;
        
        while(list1 && list2) {
            if(list1->val < list2->val) {
                ListNode* node = new ListNode(list1->val);
                ptr->next = node;
                list1 = list1->next;
            } else {
                ListNode* node = new ListNode(list2->val);
                ptr->next = node;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        
        if(list1 == NULL) list1 = list2;
        ptr->next = list1;
        
        return res.next;
    }
};