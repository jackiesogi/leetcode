class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = -1;
        int mid_end = -1;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            cout << mid;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                mid_end = mid;
                break;
            }
        }

        if (mid_end == -1) {
            return {-1, -1};
        }

        while (mid_end < nums.size()) {
            if (nums[mid_end] == target) {
                ++mid_end;
            } else {
                break;
            }
        }

        while (mid >= 0) {
            if (nums[mid] == target) {
                --mid;
            } else {
                break;
            }
        }

        return {mid + 1, mid_end - 1};
    }
};