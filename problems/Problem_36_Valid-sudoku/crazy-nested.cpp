class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> set;

        for (int i = 0; i < board.size(); ++i) {
            set.clear();
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.' && set.contains(board[i][j])) {
                    return false;
                }
                set.insert(board[i][j]);
            }
        }

        for (int i = 0; i < board[0].size(); ++i) {
            set.clear();
            for (int j = 0; j < board.size(); ++j) {
                if (board[j][i] != '.' && set.contains(board[j][i])) {
                    return false;
                }
                set.insert(board[j][i]);
            }
        }

        int box_row = board.size() / 3;
        int box_col = board.at(0).size() / 3;

        array<int, 3> xs = {0, 1, 2};
        array<int, 3> ys = {0, 1, 2};

        for (int i = 0; i < box_row; ++i) {
            for (int j = 0; j < box_col; ++j) {
                set.clear();
                for (int &x : xs) {
                    for (int &y : ys) {
                        char c = board[i * 3 + x][j * 3 + y];
                        if (c != '.' && set.contains(c)) {
                            return false;
                        }
                        set.insert(c);
                    }
                }
            }
        }
        return true;
    }
};