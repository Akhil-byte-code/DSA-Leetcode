class Solution {
public:
    int n;
    vector<vector<int>> g;

    vector<int> parent, depth, heavy, head, pos, sz;
    int curPos = 0;

    struct BIT {
        int n;
        vector<int> bit;

        BIT(int n = 0) : n(n), bit(n + 1, 0) {}

        void add(int idx, int val) {
            idx++;
            while (idx <= n) {
                bit[idx] ^= val;
                idx += idx & -idx;
            }
        }

        int pref(int idx) {
            idx++;
            int res = 0;
            while (idx > 0) {
                res ^= bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }

        int query(int l, int r) {
            return pref(r) ^ (l ? pref(l - 1) : 0);
        }
    };

    int dfs(int v, int p) {
        parent[v] = p;
        sz[v] = 1;

        int best = 0;

        for (int to : g[v]) {
            if (to == p) continue;

            depth[to] = depth[v] + 1;

            int sub = dfs(to, v);
            sz[v] += sub;

            if (sub > best) {
                best = sub;
                heavy[v] = to;
            }
        }

        return sz[v];
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = curPos++;

        if (heavy[v] != -1)
            decompose(heavy[v], h);

        for (int to : g[v]) {
            if (to == parent[v] || to == heavy[v])
                continue;
            decompose(to, to);
        }
    }

    int pathQuery(int a, int b, BIT &bit) {
        int ans = 0;

        while (head[a] != head[b]) {
            if (depth[head[a]] < depth[head[b]])
                swap(a, b);

            ans ^= bit.query(pos[head[a]], pos[a]);
            a = parent[head[a]];
        }

        if (depth[a] > depth[b])
            swap(a, b);

        ans ^= bit.query(pos[a], pos[b]);
        return ans;
    }

    vector<bool> palindromePath(
        int N,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        n = N;
        g.assign(n, {});

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        sz.resize(n);

        dfs(0, -1);
        decompose(0, 0);

        BIT bit(n);

        vector<int> curMask(n);

        for (int i = 0; i < n; i++) {
            curMask[i] = 1 << (s[i] - 'a');
            bit.add(pos[i], curMask[i]);
        }

        vector<bool> ans;

        for (string &q : queries) {
            stringstream ss(q);

            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;

                ss >> u >> c;

                int newMask = 1 << (c - 'a');

                if (newMask != curMask[u]) {
                    bit.add(pos[u], curMask[u]); // remove old
                    bit.add(pos[u], newMask);    // add new
                    curMask[u] = newMask;
                }
            } else {
                int u, v;
                ss >> u >> v;

                int mask = pathQuery(u, v, bit);

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
