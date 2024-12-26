class Solution {
 public:
    int maxArea(const vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = -1;
        int max_area = -1;

        while (left < right) {
            area = (right - left) * min(height.at(left), height.at(right));
            max_area = (area > max_area) ? area : max_area;
            if (height.at(left) < height.at(right)) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};
