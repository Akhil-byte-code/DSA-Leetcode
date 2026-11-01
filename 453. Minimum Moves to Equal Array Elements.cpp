class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int mn = nums[0];
        for (int x : nums) {
            sum += x;
            mn = min(mn, x);
        }
        return (int)(sum - (long long)nums.size() * mn);
    }
};
