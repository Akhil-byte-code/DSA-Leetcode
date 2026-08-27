class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";
        int n = s.size();

        // Match target prefix as much as possible
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
            } else {
                break;
            }
        }

        // Backtrack from the matched prefix
        while (true) {
            int pos = ans.size();

            // Try to place the smallest character > target[pos]
            if (pos < n) {
                int x = target[pos] - 'a';

                for (int c = x + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        string result = ans;
                        result += char('a' + c);
                        freq[c]--;

                        for (int j = 0; j < 26; j++) {
                            result.append(freq[j], char('a' + j));
                        }

                        return result;
                    }
                }
            }

            // No greater character possible here, backtrack
            if (ans.empty()) return "";

            char last = ans.back();
            ans.pop_back();
            freq[last - 'a']++;
        }
    }
};
