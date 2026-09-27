class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";

        for (char ch : s) {

            // Opening bracket
            if (ch == '(') {
                st.push(curr);
                curr = "";
            }

            // Closing bracket
            else if (ch == ')') {
                reverse(curr.begin(), curr.end());

                curr = st.top() + curr;
                st.pop();
            }

            // Normal character
            else {
                curr += ch;
            }
        }

        return curr;
    }
};
