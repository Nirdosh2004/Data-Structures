   class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //time and space = O(1) #because loop runs for only 9*9 times 
        // We're going to keep track of numbers we've seen in each row, column, and box.
        vector<unordered_set<char>> rows(9), cols(9), box(9);
        
        // This lambda function helps us check if a number exists in a set and adds it if not.
        auto exists = [](unordered_set<char>& s, char val){
            return s.insert(val).second;
        };

        // Now, let's go through each cell in the Sudoku board.
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                // If the cell is empty, we move on to the next one.
                if (num == '.') 
                    continue;
                // Now, we check if the current number has already been seen
                // in the same row, column, or the 3x3 box it belongs to.
                if (!exists(rows[i], num) || !exists(cols[j], num) || !exists(box[(i / 3) * 3 + j / 3], num)) {
                    return false; // If we find a repeated number, the Sudoku board is invalid.
                }
            }
        }
        // If we reach here, it means we didn't find any issues, so the Sudoku board is valid.
        return true;
    }
};
