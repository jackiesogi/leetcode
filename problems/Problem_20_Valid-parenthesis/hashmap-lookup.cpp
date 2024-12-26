class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> open = {
            {'(', ')'}, {'[', ']'}, {'{', '}'}
        };
        
        stack<char> buf;
        for(int i = 0; i < s.size(); ++i) {
            if(open.contains(s[i])) {
                buf.push(s[i]);
            } else {
                if(buf.empty() || open[buf.top()] != s[i]) {
                    return false;
                } else {
                    buf.pop();
                }
            }
        }
        return buf.empty();
    }
};