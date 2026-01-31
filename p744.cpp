class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = -1;
        int r = letters.size();
        if (letters[0] > target || letters[r - 1] <= target) {
            return letters[0];
        }
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (letters[mid] > target) {
                r = mid; 
            } else {
                l = mid;
            }
        }
        return letters[r];

    }
};