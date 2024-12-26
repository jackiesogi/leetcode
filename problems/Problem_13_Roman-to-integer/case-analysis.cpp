class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int sum = 0;
        
        unordered_map<char, int> u = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000} 
        };

        unordered_map<string, int> ex = {
            {"IV", 4}, {"IX", 9}, {"XL", 40},
            {"XC", 90}, {"CD", 400}, {"CM", 900}
        };

        while(i < s.size()) {
            char c = s.at(i);
            if(c == 'V' || c == 'L' || c == 'D' || c == 'M') {
                sum += u[c];
                ++i;
            } else {  /* Started with I, V, X, C */
                if(i + 1 >= s.size()) {
                    sum += u[c];
                    ++i;
                } else {
                    string str;
                    str.push_back(c);
                    str.push_back(s.at(i + 1));
                    if(ex.find(str) != ex.end()) {  /* True Exception: IV, XC */
                        sum += ex[str];
                        i += 2;
                    } else {  /* False Exception: II, CI */
                        sum += u[c];
                        ++i;
                    }
                }
            }
        }
        return sum;
    }
};