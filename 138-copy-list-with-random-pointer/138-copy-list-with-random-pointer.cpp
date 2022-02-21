/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *copy, *newHead, *copyPtr;
        newHead = head;
        map<Node*, Node*> ref;
        copy = new Node(0);
        copyPtr = copy;
        
        while(newHead) {
            copyPtr->next = new Node(newHead->val);
            copyPtr = copyPtr->next;
            ref[newHead] = copyPtr; // save in map
            newHead = newHead->next;
        }
        
        newHead = head;
        copyPtr = copy->next;
        
        while(newHead) {
            if(newHead->random)
                copyPtr->random = ref[newHead->random];
            newHead = newHead->next;
            copyPtr = copyPtr->next;
        }
        return copy->next;
    }
};