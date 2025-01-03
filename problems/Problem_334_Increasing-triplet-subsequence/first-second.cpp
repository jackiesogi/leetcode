class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                // 更新第一個最小值
                first = num;
            } else if (num <= second) {
                // 更新第二個最小值
                second = num;
            } else {
                // 找到一個數字大於 first 和 second
                return true;
            }
        }

        return false;
    }
};

