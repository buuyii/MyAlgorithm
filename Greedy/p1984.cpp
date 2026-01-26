#include <algorithm>
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int min = 1000000;
        int n = nums.size();
        for (int i = 0; i<= n-k; i++) {
            int r = nums[i + k - 1] - nums[i];
            if (r < min) {
                min = r;
            }
        }
        return min;
    }
};