class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write_pos = 0;
        unordered_map<int, bool> u;

        for (int i = 0; i < nums.size(); ++i) {
            if (u.find(nums[i]) == u.end()) {
                nums[write_pos++] = nums[i];
                u[nums[i]] = true;
            }
        }
        return write_pos;
    }
};
