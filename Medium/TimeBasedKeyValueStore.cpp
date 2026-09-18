#include <vector>
#include <string>
#include <unordered_map>

using namespace std; 

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (store.count(key) == 0) {
            return "";
        }

        const vector<pair<int, string>>& values = store[key]; 
        
        int n = values.size(); 
        int low = 0; 
        int high = n-1; 
        int mid;
        string ans = ""; 

        while (low <= high) {
            mid = low + (high-low)/2;

            if (values[mid].first <= timestamp) { 
                ans = values[mid].second; 
                low = mid+1; 
            } else {
                high = mid-1; 
            }
        }

        return ans;
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */