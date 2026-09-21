class Solution {
public:

    // Brute Force Approach
    // Time: O(n^3)
    // Space: O(k)

    // int solve(int i, int j, vector<int>& nums, int k) {
    //     long long prod = 1;

    //     for (int t = i; t <= j; t++) {
    //         prod = (prod * nums[t]) % k;
    //     }

    //     return prod;
    // }

    // vector<long long> resultArray(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<long long> result(k, 0);

    //     for (int i = 0; i < n; i++) {
    //         for (int j = i; j < n; j++) {
    //             int x = solve(i, j, nums, k);
    //             result[x]++;
    //         }
    //     }

    //     return result;
    // }


    // Optimized Approach
    // Time: O(n * k)
    // Space: O(k)

    vector<long long> resultArray(vector<int>& nums, int k) {

        int n = nums.size();

        vector<long long> result(k, 0);
        vector<long long> prevCount(k, 0);

        for (int i = 0; i < n; i++) {

            vector<long long> currCount(k, 0);

            // Start new subarray
            int currElementRemainder = nums[i] % k;
            currCount[currElementRemainder]++;

            // Extend previous subarrays
            for (int oldRem = 0; oldRem < k; oldRem++) {

                int newRemain =
                    ((long long)oldRem * nums[i]) % k;

                currCount[newRemain] += prevCount[oldRem];
            }

            prevCount = move(currCount);

            // Add current counts to result
            for (int x = 0; x < k; x++) {
                result[x] += prevCount[x];
            }
        }

        return result;
    }
};
