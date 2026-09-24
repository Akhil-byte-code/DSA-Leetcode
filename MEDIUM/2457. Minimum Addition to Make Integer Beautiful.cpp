class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long original = n;
        long long place = 1;

        while (true) {
            long long temp = n;
            int sum = 0;

            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            if (sum <= target)
                return n - original;

            long long digit = (n / place) % 10;
            long long add = (10 - digit) % 10;

            n += add * place;

            place *= 10;
        }
    }
};
