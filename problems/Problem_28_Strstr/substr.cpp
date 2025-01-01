class Solution {
public:
    int strStr(string haystack, string needle) {
        int window_size = needle.size();
        int start_pos = 0;
        int end_pos = start_pos + window_size;

        while (end_pos <= haystack.size()) {
            string sub = haystack.substr(start_pos, window_size);
            if (sub == needle) {
                return start_pos;
            } else {
                end_pos++;
                start_pos++;
            }
        }
        return -1;
    }
};