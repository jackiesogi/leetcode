class Solution {
private:
    string runLengthEncode(const string &input) {
        string result;
        char c;
        int i = 0;
        while (i < input.size()) {
            c = input.at(i);
            int count = 0;
            while (i < input.size() && input.at(i) == c) {
                ++i;
                ++count;
            }
            result += to_string(count);
            result.push_back(c);
        }
        return result;
    }

public:
    string countAndSay(int n) {
        string current = "1";
        while (--n) {
            current = runLengthEncode(current);
        }
        return current;
    }
};