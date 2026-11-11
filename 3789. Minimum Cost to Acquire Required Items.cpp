class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long m = min(need1, need2);

        long long pairCost = min((long long)costBoth, (long long)cost1 + cost2);
        long long ans = m * pairCost;

        long long rem1 = need1 - m;
        long long rem2 = need2 - m;

        ans += rem1 * min(cost1, costBoth);
        ans += rem2 * min(cost2, costBoth);

        return ans;
    }
};
