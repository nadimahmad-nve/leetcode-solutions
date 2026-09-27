class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0; 
        if (n == 1) return 1; 
        if (n == 2) return 1; 

        int t0 = 0; 
        int t1 = 1; 
        int t2 = 1; 

        int threeBack = t0; 
        int twoBack = t1; 
        int oneBack = t2; 

        for(int i=3; i<=n; i++) { 
            int temp = oneBack;
            oneBack = threeBack + twoBack + oneBack; 

            int temp2 = twoBack; 
            twoBack = temp; 

            threeBack = temp2; 
        }

        return oneBack; 
    }
};