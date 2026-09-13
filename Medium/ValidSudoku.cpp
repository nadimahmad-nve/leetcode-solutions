#include <vector>

using namespace std; 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][10] = {false};
        bool columns[9][10] = {false};
        bool boxes[9][10] = {false};

        for(int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j] == '.') continue; 
                
                int num = board[i][j] - '0';
                int box_num = ((i/3) * 3) + (j/3);  

                
                if (rows[i][num] == true) return false; 
                if (columns[j][num] == true) return false; 
                if (boxes[box_num][num] == true) return false;
                
                rows[i][num] = true; 
                columns[j][num] = true; 
                boxes[box_num][num] = true; 
            }
        }

        return true; 
    }
};