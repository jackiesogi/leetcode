class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix_sum = 0;
        int suffix_sum = 0;
        for (const int & n : nums) {
            suffix_sum += n;
        }

        for (int i = 0; i < nums.size(); ++i) {
            suffix_sum -= nums[i];
            if (suffix_sum == prefix_sum) {
                return i;
            }
            prefix_sum += nums[i];
        }
        return -1;
    }
};

