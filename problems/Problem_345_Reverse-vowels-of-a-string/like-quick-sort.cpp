class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'A' ||
               c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'u';
    }
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        //unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U'};

        /* Move two pointers toward the center */
        while (left <= right) {
            /* Find the vowel from the left side */
            while (left < s.size() && isVowel(s[left]) == false) {
                ++left;
            }

            /* Find the vowel from the right side */ 
            while (right >= 0 && isVowel(s[right]) == false) {
                --right;
            }

            if (left < right) {
                swap(s[left], s[right]);
            }
            ++left;
            --right;
        }

        return s;
    }
};
