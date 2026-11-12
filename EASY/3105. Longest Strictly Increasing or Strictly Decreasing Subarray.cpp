class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1, best = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {        // going up
                inc++;
                dec = 1;
            } else if (nums[i] < nums[i - 1]) { // going down
                dec++;
                inc = 1;
            } else {                            // equal: breaks both
                inc = dec = 1;
            }
            best = max(best, max(inc, dec));
        }
        return best;
    }
};
