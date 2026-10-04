class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // '*' as ')'
                high++;  // '*' as '('
            }

            // We cannot have negative minimum
            if (low < 0) {
                low = 0;
            }

            // Even maximum possible balance is negative
            if (high < 0) {
                return false;
            }
        }

        // If minimum balance can be 0, valid
        return low == 0;
    }
};
