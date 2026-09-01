#include <vector> 

using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price, profit;
        min_price = prices[0];
        profit = 0; 

        for(int i=1; i<prices.size(); i++) {
            min_price = min(min_price, prices[i]);

            profit = max(profit, prices[i] - min_price);  
        }

        return profit; 
    }
};