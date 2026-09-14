#include <vector>

using namespace std; 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(); 
        int left = 0; 
        int right = n-1; 
        int area = 0; 

        while (left < right) { 
            int new_area = min(height[left], height[right]) * (right-left); 

            area = max(new_area, area); 

            if (height[left] > height[right]) {
                right--; 
            } else { 
                left++; 
            }
        }

        return area; 
    }
};