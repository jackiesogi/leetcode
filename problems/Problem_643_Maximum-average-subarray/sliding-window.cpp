class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int max_sum, core_sum = 0;

        for (int i = 0; i < k; ++i) {
            core_sum += nums[i];
        }

        max_sum = core_sum;

        for (int i = k; i < nums.size(); ++i) {
            core_sum -= nums[i - k];
            core_sum += nums[i];
            max_sum = max(max_sum, core_sum);
        }
        return max_sum / (double)k;
    }
};
