#include <vector>

using namespace std; 

class Solution {
private:
    bool check(int k, vector<int>& piles, int h) { 
        long long num_hours = 0;

        for(int i=0; i<piles.size(); i++) {
            if (piles[i] <= k) { 
                num_hours++; 
            } else { 
                num_hours += ceil((double)piles[i]/k); 
            }
        }

        if (num_hours <= h) { 
            return true; 
        } else { 
            return false; 
        }
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; 
        int high = 1000000000; 
        int mid, ans; 

        while(low <= high) { 
            mid = low + (high-low)/2;

            if(check(mid, piles, h)) { 
                ans = mid; 
                high = mid-1; 
            } else { 
                low = mid+1; 
            }
        }

        return ans; 
    }
};