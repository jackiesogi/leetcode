class Solution {
public:
    bool isValid(string s) {
        // Map matching pairs using a direct lookup table
        char match[128] = {};
        match['('] = ')';
        match['['] = ']';
        match['{'] = '}';

        stack<char> buf;
        for (char c : s) {
            if (match[c]) {  // If it is an opening bracket
                buf.push(c);
            } else {  // It is a closing bracket
                if (buf.empty() || match[buf.top()] != c) {
                    return false;
                }
                buf.pop();
            }
        }
        return buf.empty();
    }
};
