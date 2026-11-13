class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

        deque<pair<int, long long>> dq;   // (index of record, covered length)
        long long S = 0, ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            long long len = 1;
            while (!dq.empty() && nums[dq.front().first] <= nums[l]) {
                S -= (long long)nums[dq.front().first] * dq.front().second;
                len += dq.front().second;
                dq.pop_front();
            }
            dq.push_front({l, len});
            S += (long long)nums[l] * len;

            while (S - (pre[r + 1] - pre[l]) > k) {
                auto &bk = dq.back();
                S -= nums[bk.first];
                if (--bk.second == 0) dq.pop_back();
                r--;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
