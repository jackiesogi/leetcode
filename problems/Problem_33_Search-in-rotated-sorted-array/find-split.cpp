#include <cstdlib>
class Solution {
public:
    int binsearch(vector<int> &nums, int start, int end, int target) {
        int left = start;
        int right = (end >= nums.size()) ? nums.size() - 1 : end;
        int mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        if (nums.size() == 1) {
            return target == nums.at(0) ? 0 : -1;
        }

        int split = 0;
        int a = 0;
        int b = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            a = nums[i];
            b = nums[i + 1];
            if (a > b) {
                split = i;
                break;
            }
        }

        int result = binsearch(nums, 0, split, target);
        if (result == -1) {
            result = binsearch(nums, split + 1, nums.size() - 1, target);
        }

        return result;
    }
};