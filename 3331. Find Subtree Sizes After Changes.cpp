class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> ch(n);
        for (int i = 1; i < n; i++) ch[parent[i]].push_back(i);

        vector<int> np(parent);        // new parent of each node
        vector<int> prevv(n, -1);      // saved last[c] for restoring on exit
        vector<int> idx(n, 0);         // next child index to visit
        vector<int> order;             // DFS preorder
        order.reserve(n);
        int last[26];
        fill(last, last + 26, -1);

        stack<int> st;
        auto enter = [&](int x) {
            int c = s[x] - 'a';
            prevv[x] = last[c];
            if (x != 0 && last[c] != -1) np[x] = last[c];
            last[c] = x;
            order.push_back(x);
            st.push(x);
        };

        enter(0);
        while (!st.empty()) {
            int x = st.top();
            if (idx[x] < (int)ch[x].size()) {
                enter(ch[x][idx[x]++]);
            } else {
                last[s[x] - 'a'] = prevv[x];   // restore on exit
                st.pop();
            }
        }

        vector<int> ans(n, 1);
        for (int i = n - 1; i >= 1; i--) {     // reverse preorder
            int x = order[i];
            ans[np[x]] += ans[x];
        }
        return ans;
    }
};
