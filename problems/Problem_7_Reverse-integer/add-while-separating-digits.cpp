class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (result > (std::numeric_limits<int32_t>::max() / 10) || 
                result < (std::numeric_limits<int32_t>::min() / 10)) {
                return 0;
            }

            result = result * 10 + digit;
        }

        return result;
    }
};
