class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1'000'000'007;
        long long even = 1, odd = 0;   // the empty prefix (sum 0) is even
        long long ans = 0;
        int parity = 0;                // parity of the current prefix sum

        for (int x : arr) {
            parity ^= (x & 1);
            if (parity) {              // current prefix odd -> pair with earlier even prefixes
                ans += even;
                odd++;
            } else {                   // current prefix even -> pair with earlier odd prefixes
                ans += odd;
                even++;
            }
            ans %= MOD;
        }
        return (int)ans;
    }
};
