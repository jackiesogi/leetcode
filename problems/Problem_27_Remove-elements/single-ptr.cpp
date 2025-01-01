class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write_pos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums.at(i) != val) {
                nums[write_pos++] = nums.at(i);
            }
        }
        return write_pos;
    }
};