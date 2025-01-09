class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> lps_len(s.size(), 0);
        int j = 0;  // 代表 prefix-suffix 長度
        
        // 計算 LPS 陣列
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[j]) {
                ++j;
                lps_len[i] = j;
            } else {
                while (j > 0 && s[i] != s[j]) {
                    j = lps_len[j - 1];  // 回退到上一次匹配的長度
                }
                if (s[i] == s[j]) {
                    ++j;
                }
                // 紀錄在第 i 個字元錢的 prefix-suffix length
                lps_len[i] = j;
            }
        }

        // LPS 的最後一個值
        int len = lps_len[s.size() - 1];

        // 確認是否可以整數次數覆蓋
        if (len > 0 && s.size() % (s.size() - len) == 0) {
            return true;
        }

        return false;
    }
};

