#include <algorithm>
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        std::sort(arr.begin(),arr.end());
        int n = arr.size();
        std::vector<vector<int>> res;
        int min = 0x7fffffff;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] < min) {
                min = arr[i + 1] - arr[i];
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] == min) {
                vector<int> t = {arr[i], arr[i + 1]};
                res.push_back(t);
            }
        }
        return res;
    }
};