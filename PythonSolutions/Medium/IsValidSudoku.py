class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        columns = [[False]*9 for i in range(9)]
        boxes = [[False]*9 for i in range(9)]
        rows = [[False]*9 for i in range(9)]

        for i in range(9):
            for j in range(9):
                if board[i][j] == ".":
                    continue 

                num = int(board[i][j])

                box_num = (i//3)*3 + j//3 

                if rows[i][num-1] == True or columns[j][num-1] == True or boxes[box_num][num-1] == True: 
                    return False 

                rows[i][num-1] = True 
                columns[j][num-1]= True
                boxes[box_num][num-1] = True 

        return True 

        