class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto findBoundary = [&] (bool findLeft) -> int {
            int left = 0;
            int right = nums.size() - 1;
            int mid = -1;
            int boundary = -1;
            while (left <= right) {
                mid = left + ((right - left) >> 1);
                if (nums[mid] < target) {
                    left = mid + 1;
                } else if (nums[mid] > target) {
                    right = mid - 1;
                } else {  /* nums[mid] == target */
                    boundary = mid;
                    if (findLeft) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
            return boundary;
        };
        int start = findBoundary(true);
        int end = findBoundary(false);
        if (start == -1) {
            return {-1, -1};
        }
        return {start, end};
    }
};