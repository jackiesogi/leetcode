class Solution {
public:
    bool isPalindrome(const string &s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s.at(i) != s.at(s.size() - i - 1)) {
                return false;
            }
        }
        return true;
    }

    string longestPalindrome(string s) {
        string longest, temp;
        for (int l = 0; l < s.size(); ++l) {
            for (int r = l; r < s.size(); ++r) {
                temp.assign(s.begin() + l, s.begin() + r + 1);
                if (isPalindrome(temp) && temp.size() > longest.size()) {
                    longest = temp;
                }
            }
        }
        return longest;
    }
};
