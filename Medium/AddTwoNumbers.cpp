struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {};
   ListNode(int x) : val(x), next(nullptr) {};
   ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0); 
        ListNode* result = dummy; 

        while (l1 != nullptr || l2 != nullptr || carry > 0) { 
            int x = 0; 

            if (l1 != nullptr) { 
                x += l1->val; 
                l1 = l1->next;
            }

            if (l2 != nullptr) { 
                x += l2->val;
                l2 = l2->next;  
            }

            if (carry != 0) { 
                x += carry; 
            }
            
            int digit = x % 10; 
            carry = x / 10; 

            ListNode* new_node = new ListNode(digit);
            result->next = new_node; 
            result = new_node;  
        }

        return dummy->next; 
    }
};