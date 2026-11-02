class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        // Place the median at index n/2 in O(n) average time
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int median = nums[n / 2];

        long long moves = 0;
        for (int x : nums) moves += abs((long long)x - median);
        return (int)moves;
    }
};
