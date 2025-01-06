class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int max_count, core_count = 0;
        for (int i = 0; i < k; ++i) {
            if (vowels.contains(s[i])) {
                ++core_count;
            }
        }

        max_count = core_count;

        for (int i = k; i < s.size(); ++i) {
            if (vowels.contains(s[i - k])) {
                --core_count;
            }
            if (vowels.contains(s[i])) {
                ++core_count;
            }
            max_count = max(core_count, max_count);
        }

        return max_count;
    }
};
