class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        // values go up to 1e6, plus x+1 -> 1e6+1
        vector<int> dp(1000003, 0);
        int ans = 1;
        
        for (int x : nums) {
            // increase x -> x+1 (use old dp[x] first)
            dp[x + 1] = dp[x] + 1;
            // keep x
            dp[x] = dp[x - 1] + 1;
            
            ans = max({ans, dp[x], dp[x + 1]});
        }
        return ans;
    }
};
