#include <set>
#include <vector> 

using namespace std; 

class Solution {
private:
    void dfs(set<pair<int,int>>& visited, int i, int j, int prevHeight, vector<vector<int>>& heights) { 
        if (visited.count({i, j}) || i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size() || heights[i][j] < prevHeight) { 
            return;
            // Already in the set OR not valid. (Indices out of range, or too low)
        }

        visited.insert({i, j}); 

        int dx[] = {1, -1, 0, 0}; 
        int dy[] = {0, 0, 1, -1}; 

        for (int k=0; k<4; k++) { 
            int new_x = i + dx[k]; 
            int new_y = j + dy[k]; 

            dfs(visited, new_x, new_y, heights[i][j], heights); 
        }

    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Find all coordinates that can reach pacific ocean
        // Find all coordinates that can reach the atlantic ocean
        // Intersect the sets 
        
        set<pair<int,int>> atlantic; 
        set<pair<int,int>> pacific; 

        int m = heights.size(); // Rows
        int n = heights[0].size(); // Columns

        for(int i=0; i<n; i++) { 
            dfs(pacific, 0, i, heights[0][i], heights);
            dfs(atlantic, m-1, i, heights[m-1][i], heights);
        }

        for(int i=0; i<m; i++) { 
            dfs(pacific, i, 0, heights[i][0], heights);
            dfs(atlantic, i, n-1, heights[i][n-1], heights);
        }

        vector<vector<int>> res; 
        for(int i=0; i<m; i++) { 
            for(int j=0; j<n; j++) { 
                if(atlantic.count({i,j}) && pacific.count({i,j})) { 
                    vector<int> temp; 
                    temp.push_back(i); 
                    temp.push_back(j); 

                    res.push_back(temp); 
                }
            }
        }


        return res; 
    }
};