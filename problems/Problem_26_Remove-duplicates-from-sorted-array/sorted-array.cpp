class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int write_pos = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[write_pos]) {
                nums[++write_pos] = nums[i];
            }
        }
        return write_pos + 1;
    }
};