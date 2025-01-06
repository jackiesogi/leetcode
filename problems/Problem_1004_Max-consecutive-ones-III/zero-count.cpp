class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, max_length = 0, zero_count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                ++zero_count;
            }

            while (zero_count > k) {
                if (nums[left] == 0) {
                    --zero_count;
                }
                ++left;
            }

            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};

