#include <unordered_map> 

using namespace std; 

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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> original_to_clone; 
        // First pass
        Node* curr = head; 
        
        while(curr != nullptr) {
            original_to_clone[curr] = new Node(curr->val); 
            curr = curr->next;
        }

        curr = head; 

        while(curr != nullptr) { 
            original_to_clone[curr]->next = original_to_clone[curr->next]; 
            original_to_clone[curr]->random = original_to_clone[curr->random]; 

            curr = curr->next; 
        }

        return original_to_clone[head]; 
    }
};