class Solution {
public:
    int maxLength = 0;
    int maxStart = 0;
    int maxEnd = 0;

    void ExpandFromCenter(const string &s, int lcenter, int rcenter) {
        int l = lcenter;
        int r = rcenter;
        while(l >= 0 && r < s.size()) {
            if(s.at(l) != s.at(r)) {
                break;
            }
            if (r - l + 1 > maxLength) {
                maxLength = r - l + 1;
                maxStart = l;
                maxEnd = r;
            }
            ++r;
            --l;
        }
    }

    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); ++i) {
            ExpandFromCenter(s, i, i);
            ExpandFromCenter(s, i, i+1);
        }
        return s.substr(maxStart, maxLength);
    }
};
