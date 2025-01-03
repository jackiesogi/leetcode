class Solution {
public:
    int compress(vector<char>& chars) {
        int insert_idx = 0;  // 用來插入壓縮後的字符
        int n = chars.size();

        for (int i = 0; i < n; ++i) {
            char base_char = chars[i];
            int runlen = 1;

            // 計算當前字符的連續長度
            while (i + 1 < n && chars[i + 1] == base_char) {
                ++i;
                ++runlen;
            }

            // 插入字符
            chars[insert_idx++] = base_char;

            // 如果連續長度大於1，則插入數字
            if (runlen > 1) {
                string runlen_str = to_string(runlen);
                for (char c : runlen_str) {
                    chars[insert_idx++] = c;
                }
            }
        }

        return insert_idx;  // 返回壓縮後的長度
    }
};

