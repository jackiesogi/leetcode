class Solution {
public:
    string reverseWords(string s) {
        string result;
        int end = s.size() - 1;

        while (end >= 0) {
            while (end >= 0 && isspace(s[end])) {
                --end;
            }

            if (end < 0) break;

            int start = end;
            while (start >= 0 && !isspace(s[start])) {
                --start;
            }

            result += s.substr(start + 1, end - start);

            result += " ";

            end = start - 1;
        }

        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};

