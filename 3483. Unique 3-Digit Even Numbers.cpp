class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;

        for (int num = 100; num <= 999; num++) {
            // Number must be even
            if (num % 2 != 0)
                continue;

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            // Count how many times each digit is available
            int count[10] = {0};

            for (int d : digits) {
                count[d]++;
            }

            // Check whether we have enough copies
            count[a]--;
            count[b]--;
            count[c]--;

            if (count[a] >= 0 && count[b] >= 0 && count[c] >= 0) {
                ans++;
            }
        }

        return ans;
    }
};
