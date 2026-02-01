class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int> n2 = nums;
        int sum = n2[0];
        n2.erase(n2.begin());
        sort(n2.begin(), n2.end());
        
        for (int i = 0; i < 2; i++) {
            sum += n2[i];
        }
        return sum;
    }
};