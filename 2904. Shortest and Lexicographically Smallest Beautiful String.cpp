class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // brute force approach 
        int n = s.length();

        for (int len = k; len <= n; len++) {
            string result = "";

            for (int start = 0; start <= n - len; start++) {
                string temp = s.substr(start, len);

                int ones = 0;
                for (char ch : temp) {
                    if (ch == '1')
                        ones++;
                }

                if (ones == k) {
                    if (result.empty() || temp < result) {
                        result = temp;  // assignment, not +=
                    }
                }
            }

            if (!result.empty())
                return result;
        }

        return "";
    }
};
