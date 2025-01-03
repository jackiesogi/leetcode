class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int start = 0;  // Represents the start of the 'descending range'
        int end = 0;
        while (end < nums.size() - 1) {
            for (int i = start; i + 1 < nums.size(); ++i) {
                if (nums.at(i + 1) - nums.at(i) > 0) {
                    start = i + 1;
                    end = i + 1;
                    break;
                } else {
                    end = i + 1;
                }
            }
        }

        sort(nums.begin() + start, nums.begin() + end + 1);

        if (start == 0) {
            return;
        }

        int j = start;
        while (nums.at(j) <= nums.at(start - 1)) {
            ++j;
        }
        swap(nums[j], nums[start - 1]);
        return;
    }
};
