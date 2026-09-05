class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // time limit exceeded
        // int n = nums.size();

        // for (int i = 0; i < n; i++) {

        //     int maxi = nums[0];
        //     int mini = nums[i];

        //     // max from 0 to i
        //     for (int j = 0; j <= i; j++) {
        //         maxi = max(maxi, nums[j]);
        //     }

        //     // min from i to n-1
        //     for (int j = i; j < n; j++) {
        //         mini = min(mini, nums[j]);
        //     }

        //     if (maxi - mini <= k) {
        //         return i;
        //     }
        // }

        // return -1;


        int n = nums.size();

        // suffixMin[i] = minimum element from i to n-1
        vector<long long> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min((long long)nums[i], suffixMin[i + 1]);
        }

        // Maintain maximum from 0 to i
        long long prefixMax = nums[0];

        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, (long long)nums[i]);

            long long instability = prefixMax - suffixMin[i];

            if (instability <= k) {
                return i;
            }
        }

        return -1;
    }
};
    
