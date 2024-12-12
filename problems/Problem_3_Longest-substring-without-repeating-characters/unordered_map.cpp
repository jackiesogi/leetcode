class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> u;  // <char, index>
        int maxlen = 0;
        int winstart = 0, winend;
        
        for (winend = 0; winend < s.size(); ++winend) {
            char c = s.at(winend);
            
            if (u.find(c) != u.end()) {
                winstart = std::max(winstart, u[c] + 1);
            }
            
            u[c] = winend;
            maxlen = std::max(maxlen, winend - winstart + 1);
        }

        return maxlen;
    }
    
};