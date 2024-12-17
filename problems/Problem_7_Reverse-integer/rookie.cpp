class Solution {
public:
    int reverse(int x) {
        int64_t result = (int64_t)x;
        int8_t positive = (result >= 0) ? 1 : -1;
        result = (result >= 0) ? (result) : (-1 * result);
        int8_t digit;
        vector<int8_t> v;

        while(result > 0) {
            digit = result % 10;
            result /= 10;
            v.push_back(digit);
        }

        result = 0;
        for(int8_t i = 0; i < v.size(); ++i) {
            result += (v.at(i) * pow(10, (v.size() - i - 1)));
            if (result > std::numeric_limits<int32_t>::max() ||
                result < std::numeric_limits<int32_t>::min()) {
                return 0;
            }
        }

        return (result * positive);
    }
};