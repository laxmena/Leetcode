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
    ListNode* partition(ListNode* head, int x) {
        deque<int> less, greater;
        ListNode* temp = head;
        while(temp != NULL) {
            if(temp->val < x) less.push_back(temp->val);
            else greater.push_back(temp->val);
            temp = temp->next;
        } 
        if(less.size() == 0 || greater.size() == 0) return head;
        temp = head;
        while(!less.empty()) {
            temp->val = less.front();
            less.pop_front();
            temp = temp->next;
        }
        while(!greater.empty()) {
            temp->val = greater.front();
            greater.pop_front();
            temp = temp->next;
        }
        return head;
    }
};