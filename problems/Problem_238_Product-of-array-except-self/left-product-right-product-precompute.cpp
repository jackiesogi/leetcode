class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int left_product = 1;
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = left_product;
            left_product *= nums[i];
        }

        int right_product = 1;
        for (int j = nums.size() - 1; j >= 0; --j) {
            result[j] *= right_product;
            right_product *= nums[j];
        }
        return result;
    }
};
