class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        int count = 0;
        string result;
        bool should_add = true;

        while(count < strs[0].size()) {
            char c = strs[0][count];
            for(int i = 1; i < strs.size(); ++i) {
                if(i >= strs.size()|| count >= strs[i].size() || strs[i][count] != c) {
                    should_add = false;
                }
            }

            if(should_add) {
                result.push_back(c);
                ++count;
            } else {
                break;
            }
        }
        return result;
    }
};