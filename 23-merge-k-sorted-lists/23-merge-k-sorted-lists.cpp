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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        pair<int, int> top;
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        ListNode head = ListNode();
        ListNode* cur = &head;
        
        int len = lists.size();
        
        // Insert values into min heap
        for(int i=0; i<len; i++) {
            ListNode* node = lists[i];
            if(node == NULL) continue;
            pq.push(make_pair(node->val, i));
        }

        // Repeat till min heap has value in it        
        while(!pq.empty()) {
            top = pq.top(); pq.pop();
            cur->next = new ListNode(top.first);
            cur = cur->next;
            int index = top.second;
            lists[index] = lists[index]->next;
            if(lists[index] != NULL) {
                pq.push(make_pair(lists[index]->val, index));
            }
        }
        
        return head.next;
    }
};