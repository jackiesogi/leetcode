class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int max = -1;
        for(int i = 0; i < height.size(); ++i) {
            int h = height.at(i);
            int w = 0;
            if(i < height.size() / 2) {
                for(int j = height.size() - 1; j >= 0; --j) {
                    if(height.at(j) >= h && j != i) {
                        w = std::abs(i - j);
                        break;
                    }
                }
            } else {
                for(int j = 0; j < height.size(); ++j) {
                    if(height.at(j) >= h && j != i) {
                        w = std::abs(i - j);
                        break;
                    }
                }
            }

            area = w * h;

            if(area > max) {
                max = area;
            }
        }
        return max;
    }
};