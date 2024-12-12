#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    std::unordered_map<int, int> x;

    int i, complement;

    for (i = 0; i < nums.size(); ++i) {

        complement = target - nums.at(i);

        if (x.find(complement) != x.end()) {
            return {x[complement], i};
        }

        x[nums.at(i)] = i;
    }

    return {};
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 7, 11, 15};
    vector<int> vec;
    vec.assign(arr, arr + 4);

    vector<int> result = twoSum(vec, 9);

    if (result.empty()) {
        cout << "No solution found.\n";
    } else {
        cout << result[0] << ", " << result[1] << "\n";
    }

    return 0;
}