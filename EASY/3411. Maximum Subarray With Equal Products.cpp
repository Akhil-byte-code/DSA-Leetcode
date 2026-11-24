class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        const long long LIMIT = 2520 * 10;   // max possible lcm * gcd

        for (int i = 0; i < n; i++) {
            long long prod = 1, g = 0, l = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                if (prod > LIMIT) break;      // can never match again

                g = std::gcd(g, (long long)nums[j]);
                l = std::lcm(l, (long long)nums[j]);

                if (prod == g * l)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
