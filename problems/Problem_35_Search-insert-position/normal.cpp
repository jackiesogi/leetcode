class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums.at(mid) < target) {
                left = mid + 1;
            } else if (nums.at(mid) > target) {
                right = mid - 1;
            } else {  /* equal */
                return mid;
            }
        }
        return right + 1;
    }
};