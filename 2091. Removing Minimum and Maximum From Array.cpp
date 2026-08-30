class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0, maxIdx = 0;

        // Find indices of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int l = min(minIdx, maxIdx);
        int r = max(minIdx, maxIdx);

        // 1. Remove both from front
        int fromFront = r + 1;

        // 2. Remove both from back
        int fromBack = n - l;

        // 3. Remove one from front and one from back
        int bothEnds = (l + 1) + (n - r);

        return min({fromFront, fromBack, bothEnds});
    }
};
