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
typedef pair<int, ListNode*> pil;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pil, vector<pil>, greater<pil>> pq;
        for(auto list: lists) {
            if(list)
                pq.push({list->val, list});
        }       
        ListNode* res = new ListNode(0), *head;
        head = res;
        while(!pq.empty()) {
            pil top = pq.top();
            pq.pop();

            ListNode* node = new ListNode(top.first);
            res->next = node;
            res = res->next;
            
            if(top.second->next) {
                top.second = top.second->next;
                pq.push({top.second->val, top.second});
            }
        }
        
        return head->next;
    }
};