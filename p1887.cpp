#include <algorithm>
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int max = 0;
        int p = 0;
        for (int i = 0; i < n/2; i++) {
            int c = nums[i] + nums[n-1-i];
            if (c > max) {
                max = c;
            }
        }
        return max;
    }
};