class Solution {
public:
    int similarPairs(vector<string>& words) {
        vector<int> masks;

        for (string word : words) {
            int mask = 0;

            for (char ch : word) {
                mask |= (1 << (ch - 'a'));
            }

            masks.push_back(mask);
        }

        int ans = 0;

        for (int i = 0; i < masks.size(); i++) {
            for (int j = i + 1; j < masks.size(); j++) {
                if (masks[i] == masks[j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
