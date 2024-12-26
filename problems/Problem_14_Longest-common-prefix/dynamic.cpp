class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        // 找出最短字符串的長度
        int min_len = INT_MAX;
        for (const string& str : strs) {
            min_len = min(min_len, (int)str.size());
        }

        // 根據數據特性動態選擇方法
        if (strs[0].size() > min_len * 2) {
            // 逐字元比較
            string result;
            for (int i = 0; i < min_len; ++i) {
                char c = strs[0][i];
                for (int j = 1; j < strs.size(); ++j) {
                    if (strs[j][i] != c) {
                        return result;
                    }
                }
                result.push_back(c);
            }
            return result;
        } else {
            // 使用第一個字符串作為初始 prefix
            string prefix = strs[0];
            for (int i = 1; i < strs.size(); ++i) {
                while (strs[i].find(prefix) != 0) {
                    prefix = prefix.substr(0, prefix.size() - 1);
                    if (prefix.empty()) {
                        return "";
                    }
                }
            }
            return prefix;
        }
    }
};
