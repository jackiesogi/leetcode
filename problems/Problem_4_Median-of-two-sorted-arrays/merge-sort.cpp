class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /* Merge two sorted arrays */
        vector<int> result;
        int s1 = nums1.size();
        int s2 = nums2.size();
        result.reserve(s1 + s2);

        /* Compare two sorted arrays */
        int i1 = 0, i2 = 0;
        while (i1 < s1 && i2 < s2) {
            if (nums1[i1] <= nums2[i2]) {
                result.push_back(nums1[i1]);
                i1++;
            } else {
                result.push_back(nums2[i2]);
                i2++;
            }
        }

        /* Dump nums1 */
        if (i1 < s1) {
            result.insert(result.end(), nums1.begin() + i1, nums1.end());
        }

        /* Dump nums2 */
        if (i2 < s2) {
            result.insert(result.end(), nums2.begin() + i2, nums2.end());
        }

        /* Calculate median */
        int s = result.size();
        if ((s & 1) == 0) { // Even size
            return (result[s >> 1] + result[(s >> 1) - 1]) / 2.0;
        } else { // Odd size
            return result[s >> 1];
        }
    }
};
