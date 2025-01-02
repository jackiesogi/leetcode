class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 0) return 0; 
        int slow = 0, fast = len - 1;
        int leftMax = 0, rightMax = 0;
        int sum = 0;

        while (slow <= fast) {
            if (height[slow] <= height[fast]) {
                if (height[slow] >= leftMax) {
                    leftMax = height[slow];
                } else {
                    sum += leftMax - height[slow];
                }
                ++slow;
            } else {
                if (height[fast] >= rightMax) {
                    rightMax = height[fast];
                } else {
                    sum += rightMax - height[fast];
                }
                --fast;
            }
        }

        return sum;
    }
};
