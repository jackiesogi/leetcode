class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int current;
        for (int i = 0; i < gain.size(); ++i) {
            current += gain[i];
            if (current > highest) {
                highest = current;
            }
        }
        return highest;
    }
};
