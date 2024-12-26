class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        
        unordered_map<char, int> u = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000} 
        };

        for(int i = 0; i < s.size(); ++i) {
            if(i + 1 < s.size() && u[s[i]] < u[s[i+1]]) {
                sum -= u[s[i]];
            } else {
                sum += u[s[i]];
            }
        }
        return sum;
    }
};