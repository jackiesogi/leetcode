class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        if (t.empty()) return false;

        int a = 0;
        int b = 0;
        while (a < s.size() && b < t.size()) {
            char ch = s.at(a);
                if (t.at(b) == ch) {
                    ++a;
                }
                ++b;
        }
        return a == s.size();
    }
};
