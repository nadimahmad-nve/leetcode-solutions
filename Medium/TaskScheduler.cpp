#include <vector>
#include <queue>
#include <unordered_map>

using namespace std; 

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;
        unordered_map<char, int> counts; 

        for (int i=0; i<tasks.size(); i++) { 
            counts[tasks[i]]++; 
        }

        for (auto const& [letter, freq] : counts) {
            if (freq > 0) {
                maxHeap.push(freq);
            }
        }

        int time = 0; 
        queue<pair<int,int>> q; 
        while(maxHeap.size() > 0 || !q.empty()) { 
            time++; 

            if (maxHeap.size() > 0) { 
                int task = maxHeap.top();
                maxHeap.pop(); 
                
                task--; 
                
                if (task > 0) { 
                    q.push({task, time+n});  
                }
            }

            if(!q.empty()) {
                pair<int, int> taskOnCooldown = q.front(); 
                if (taskOnCooldown.second == time) { 
                    // Cooldown finished, back onto stack
                    q.pop(); 
                    maxHeap.push(taskOnCooldown.first); 
                }
            } 
        }

        return time; 
    }
};