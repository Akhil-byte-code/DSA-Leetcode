class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int len = l; len <= r; len++) {
                int j = i + len;
                if (j > n) break;               // subarray would run past the end
                int s = pre[j] - pre[i];
                if (s > 0) ans = min(ans, s);   // only positive sums count
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
