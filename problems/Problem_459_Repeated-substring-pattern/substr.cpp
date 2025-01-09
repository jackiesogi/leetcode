class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int len = 1; len <= s.size() / 2; ++len) {
            string sub = s.substr(0, len);
            bool match = true;
            for (int j = len; j < s.size(); j += len) {
                string comp = s.substr(j, len);
                if (sub != comp) {
                    match = false;
                    break;
                }
            }
            if (match == true) {
                return true;
            }
        }
        return false;
    }
};
