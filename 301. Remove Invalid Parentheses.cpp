class Solution {
public:
    vector<string> ans;

    void solve(string &s, int index, int leftRem, int rightRem,
               int leftCount, int rightCount, string curr) {

        // End of string
        if (index == s.size()) {

            // All required removals must be done
            if (leftRem == 0 && rightRem == 0 &&
                leftCount == rightCount) {
                
                ans.push_back(curr);
            }

            return;
        }

        char ch = s[index];

        // Case 1: Current character is '('
        if (ch == '(') {

            // Option 1: Remove it
            if (leftRem > 0) {
                solve(s, index + 1, leftRem - 1, rightRem,
                      leftCount, rightCount, curr);
            }

            // Option 2: Keep it
            solve(s, index + 1, leftRem, rightRem,
                  leftCount + 1, rightCount, curr + ch);
        }

        // Case 2: Current character is ')'
        else if (ch == ')') {

            // Option 1: Remove it
            if (rightRem > 0) {
                solve(s, index + 1, leftRem, rightRem - 1,
                      leftCount, rightCount, curr);
            }

            // Option 2: Keep it only if it doesn't make
            // the number of ')' greater than '('
            if (leftCount > rightCount) {
                solve(s, index + 1, leftRem, rightRem,
                      leftCount, rightCount + 1, curr + ch);
            }
        }

        // Case 3: Letter
        else {
            solve(s, index + 1, leftRem, rightRem,
                  leftCount, rightCount, curr + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

        // Find minimum number of '(' and ')' to remove
        for (char ch : s) {

            if (ch == '(') {
                leftRem++;
            }
            else if (ch == ')') {

                if (leftRem > 0) {
                    leftRem--;
                }
                else {
                    rightRem++;
                }
            }
        }

        solve(s, 0, leftRem, rightRem, 0, 0, "");

        // Remove duplicates
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};
