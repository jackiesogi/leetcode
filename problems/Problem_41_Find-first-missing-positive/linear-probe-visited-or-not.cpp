class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            map.insert(make_pair(nums[i], i));
        }

        int j;
        for (j = 1; j <= INT_MAX; ++j) {
            if (map.contains(j) == false) {
                break;
            }
        }
        return j;
    }
};