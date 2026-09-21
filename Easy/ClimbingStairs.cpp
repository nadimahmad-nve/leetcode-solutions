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