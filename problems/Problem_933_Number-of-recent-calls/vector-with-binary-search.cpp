class RecentCounter {
public:
    RecentCounter() {

    }
    int get_timestamp(int timestamp) {
        int left = 0;
        int right = timestamps.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (timestamps[mid] < timestamp) {
                left = mid + 1;
            } else if (timestamps[mid] > timestamp) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return left; // the first greater element idx;
    }

    //int get_range(int start, int end) {        
    //    return get_timestamp(end) - get_timestamp(start);
    //}

    int ping(int t) {
        timestamps.push_back(t);
        return timestamps.size() - get_timestamp(t - 3000);
    }

private:
        vector<int> timestamps;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
