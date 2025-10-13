// LeetCode-ready C++ solution
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // trackers: rows[r][d], cols[c][d], boxes[b][d]
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') continue;           // empty cell skip

                int d = ch - '1'; // digit index 0..8 for '1'..'9'
                if (d < 0 || d > 8) return false;  // safety (not needed for valid input)

                // box index: (r/3)*3 + (c/3)
                int b = (r / 3) * 3 + (c / 3);

                // check duplicates
                if (rows[r][d]) return false;     // same digit seen in this row
                if (cols[c][d]) return false;     // same digit seen in this column
                if (boxes[b][d]) return false;    // same digit seen in this 3x3 box

                // mark seen
                rows[r][d] = cols[c][d] = boxes[b][d] = true;
            }
        }
        return true;
    }
};