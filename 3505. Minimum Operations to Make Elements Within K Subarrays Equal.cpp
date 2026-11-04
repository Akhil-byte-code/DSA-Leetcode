class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int W = n - x + 1;
        vector<long long> cost(W);

        multiset<int> lo, hi;
        long long sumLo = 0, sumHi = 0;

        auto rebalance = [&]() {
            while (lo.size() > hi.size() + 1) {
                auto it = prev(lo.end());
                int v = *it;
                lo.erase(it);
                sumLo -= v;
                hi.insert(v);
                sumHi += v;
            }
            while (lo.size() < hi.size()) {
                auto it = hi.begin();
                int v = *it;
                hi.erase(it);
                sumHi -= v;
                lo.insert(v);
                sumLo += v;
            }
        };
        auto add = [&](int v) {
            if (lo.empty() || v <= *lo.rbegin()) {
                lo.insert(v);
                sumLo += v;
            } else {
                hi.insert(v);
                sumHi += v;
            }
            rebalance();
        };
        auto remove = [&](int v) {
            if (!lo.empty() && v <= *lo.rbegin()) {
                lo.erase(lo.find(v));
                sumLo -= v;
            } else {
                hi.erase(hi.find(v));
                sumHi -= v;
            }
            rebalance();
        };

        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) remove(nums[i - x]);
            if (i >= x - 1) {
                long long m = *lo.rbegin();
                cost[i - x + 1] = m * (long long)lo.size() - sumLo
                                + sumHi - m * (long long)hi.size();
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<long long> prev(n + 1, 0), cur(n + 1, INF);
        for (int j = 1; j <= k; j++) {
            fill(cur.begin(), cur.end(), INF);
            for (int i = 1; i <= n; i++) {
                cur[i] = cur[i - 1];
                if (i >= x && prev[i - x] < INF)
                    cur[i] = min(cur[i], prev[i - x] + cost[i - x]);
            }
            swap(prev, cur);
        }
        return prev[n];
    }
};
