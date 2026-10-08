class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count = 0;

        for (char ch : s) {
            if (ch == '(') {
                count++;

                // Don't add outermost '('
                if (count > 1) {
                    ans += ch;
                }
            }
            else {
                count--;

                // Don't add outermost ')'
                if (count > 0) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};
