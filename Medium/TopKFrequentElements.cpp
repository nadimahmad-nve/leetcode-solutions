#include <vector>  
#include <unordered_map> 
#include <queue> 

using namespace std; 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i=0; i<nums.size(); i++) { 
            occurrences[nums[i]]++; 
        }

        for (auto pair : occurrences) { 
            int num = pair.first; 
            int freq = pair.second; 

            minHeap.push({freq, num}); 

            if (minHeap.size() > k) { 
                minHeap.pop();
            }
        }

        vector<int> most_frequent; 

        while (!minHeap.empty()) { 
            int lowest_freq = minHeap.top().second; 
            most_frequent.push_back(lowest_freq);
            minHeap.pop();
        }

        return most_frequent; 
    }
};