struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {};
   ListNode(int x) : val(x), next(nullptr) {};
   ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head; 
        ListNode* fast = head; 

        // Find the middle
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next; 
            if (fast == nullptr) { 
                break;
            }

            slow = slow->next;
        }

        // Slow is now at the middle
        // Reverse
        ListNode* second_half = slow->next; 
        slow->next = nullptr; 

        ListNode* prev = nullptr;
        ListNode* curr = second_half; 
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = nextNode; 
        }

        ListNode* list1 = head; 
        ListNode* list2 = prev; 
        
        // Stitch the lists together
        while (list2 != nullptr) {
            ListNode* tmp1 = list1->next;
            ListNode* tmp2 = list2->next;

            list1->next = list2; 
            list2->next = tmp1;  

            list1 = tmp1;        
            list2 = tmp2;        
        }
    }
};