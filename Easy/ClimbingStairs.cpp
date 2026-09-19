struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {};
   ListNode(int x) : val(x), next(nullptr) {};
   ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1; 
        } 
        if (n == 2) { 
            return 2; 
        }

        int oneStepBefore = 2; 
        int twoStepsBefore = 1; 
        int currentWays = 0; 

        for(int i=3; i<=n; i++) { 
            currentWays = oneStepBefore + twoStepsBefore; 
            twoStepsBefore = oneStepBefore;
            oneStepBefore = currentWays; 
        }

        return currentWays; 

    }
};