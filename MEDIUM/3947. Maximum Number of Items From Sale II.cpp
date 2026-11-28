class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<long long> cnt(n + 2, 0), S(n + 2, 0);
        for (auto& it : items) cnt[it[0]]++;
        for (int f = 1; f <= n; f++)
            for (int m = f; m <= n; m += f) S[f] += cnt[m];

        long long pm = LLONG_MAX;
        vector<pair<long long, long long>> v; // (price, gain)
        for (auto& it : items) {
            pm = min(pm, (long long)it[1]);
            long long g = S[it[0]] - 1;
            if (g > 0) v.push_back({it[1], g});
        }
        sort(v.begin(), v.end());

        long long rem = budget, k = 0;
        for (auto& [p, g] : v) {
            if (p >= 2 * pm) break;
            long long can = rem / p;
            if (can >= g) {
                k += g;
                rem -= g * p;
            } else {
                k += can;
                rem -= can * p;
                break;
            }
        }
        long long ans = 2 * k + rem / pm;
        return (int)ans;
    }
};
