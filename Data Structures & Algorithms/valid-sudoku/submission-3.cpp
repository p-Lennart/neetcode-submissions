class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        size_t n = board.size();

        vector<vector<int>> quadrants((n / 3) * (n / 3), vector<int>(9));
        vector<vector<int>> xcoords(9, vector<int>(n));
        vector<vector<int>> ycoords(9, vector<int>(n));
        
        for (size_t row{}; row < n; row++) {
            for (size_t col{}; col < board[row].size(); col++) {
                char c = board[row][col];
                if (c == '.') {
                    continue;
                }

                int digit = c - '0';

                xcoords[digit-1][col] += 1;
                ycoords[digit-1][row] += 1;
                // cout << "xcoord " << digit << "-" << col << ": " << xcoords[digit-1][col] << "\n";
                // cout << "ycoord " << digit << "-" << row << ": " << ycoords[digit-1][row] << "\n";

                int quad_num = (col / 3) + (3 * (row / 3));
                // cout << "Quadrant num of [" << col << "," << row << "]=" << digit << " is" << quad_num << "\n"; 
                quadrants[quad_num][digit-1] += 1;

                if (xcoords[digit-1][col] > 1 
                    || ycoords[digit-1][row] > 1
                    || quadrants[quad_num][digit-1] > 1) {
                    // same digit in same cross or quadrant
                    cout << "Crashout at [" << col << "," << row << "]=" << digit << ":\n";
                    cout << "Quad: " << quadrants[quad_num][digit-1] << "\n";
                    return false;
                }
            }
        }

        return true; 
    }
};
