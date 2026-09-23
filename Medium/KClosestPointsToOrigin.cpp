#include <vector>
#include <queue>

using namespace std; 


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        vector<vector<int>> res; 

        for (int i=0; i<points.size(); i++) { 
            int dist = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]); // No need to square root, irrelevant

            maxHeap.push({dist, points[i]});

            if (maxHeap.size() > k) { 
                maxHeap.pop(); 
            }
        }

        while (maxHeap.size() > 0) { 
            vector<int> coords = maxHeap.top().second;
            maxHeap.pop(); 
            res.push_back(coords); 
        }

        return res; 
    }
};