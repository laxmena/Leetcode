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
    void reorderList(ListNode* head) {
        vector<ListNode*> cache;
        ListNode* p = head;
        while(p) {
            cache.push_back(p);
            p = p->next;
        }
        int n = cache.size();
        if(n < 2) return;
        for(int i=0; i<n; i++) {
            if(n/2 >i) { cache[i]->next = cache[n-i-1]; }
            else { cache[i]->next = cache[n-i]; }
        }
        cache[n/2]->next = NULL;
    }
};