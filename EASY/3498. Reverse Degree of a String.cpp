class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            int reversePosition = 'z' - s[i] + 1;
            sum += reversePosition * (i + 1);
        }

        return sum;
    }
};
