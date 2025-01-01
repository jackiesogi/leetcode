class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 使用三個陣列來追蹤行、列和小九宮格中的數字
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;

                // 計算小九宮格的索引
                int boxIndex = (i / 3) * 3 + (j / 3);

                // 檢查是否違反規則
                if (rows[i].count(c) || cols[j].count(c) || boxes[boxIndex].count(c)) {
                    return false;
                }

                // 加入對應的集合
                rows[i].insert(c);
                cols[j].insert(c);
                boxes[boxIndex].insert(c);
            }
        }

        return true;
    }
};
