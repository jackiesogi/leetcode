class Solution {
public:
    bool isPalindrome(int x) {
        int64_t reversed = 0;
        int64_t temp = x;
        while(temp > 0) {
            reversed = (reversed * 10) + (temp % 10);
            temp /= 10;
        }
        return x == reversed;
    }
};