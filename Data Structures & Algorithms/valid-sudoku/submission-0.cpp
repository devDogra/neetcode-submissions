class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        // row[i][j] => freq of number 'j' in the ith row. if more than 1 
        // then invalid 
        vector<vector<int>> row(n, vector<int>(n+1, 0));
        vector<vector<int>> col(n, vector<int>(n+1, 0));
        vector<vector<int>> box(n, vector<int>(n+1, 0));

        
        int BOX_SIZE = 3;
        // 8,4  => boxidx 2, 1 => box 7
        // 2nd row, 1st col ==> 2*3 + 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char numchar = board[i][j];
                if (numchar == '.') continue;
                int num = numchar - '0';

                int a = ++row[i][num];
                int b = ++col[j][num];
                // box
                int box_idx_x = i / BOX_SIZE;
                int box_idx_y = j / BOX_SIZE;
                int box_idx = ((box_idx_x) * BOX_SIZE) + box_idx_y;

                int c = ++box[box_idx][num];

                if (a > 1 || b > 1 || c > 1) return false;

            }
        }

        return true;
    }
};
