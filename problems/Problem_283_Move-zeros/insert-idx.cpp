class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insert_idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums.at(i) != 0) {
                swap(nums[i], nums[insert_idx++]);
            }
        }
        while (insert_idx < nums.size()) {
            nums[insert_idx++] = 0;
        }
    }
};

