class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
         int n = nums.size();
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                int diff = abs(nums[i] - nums[j]);

                if (diff== k) {
                    count++;
                }
            }
        }

        return count;
    }
};
