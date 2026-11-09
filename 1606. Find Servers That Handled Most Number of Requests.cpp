class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> cnt(k, 0);

        set<int> avail;                        // free servers, sorted by id
        for (int i = 0; i < k; i++) avail.insert(i);

        // min-heap of (finish time, server id) for busy servers
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        for (int i = 0; i < n; i++) {
            long long t = arrival[i];

            // 1. free every server whose job finished by time t
            while (!busy.empty() && busy.top().first <= t) {
                avail.insert(busy.top().second);
                busy.pop();
            }

            // 2. all busy -> drop the request
            if (avail.empty()) continue;

            // 3. first free server with id >= i % k, else wrap to the smallest id
            auto it = avail.lower_bound(i % k);
            if (it == avail.end()) it = avail.begin();

            int s = *it;
            avail.erase(it);
            cnt[s]++;
            busy.push({t + load[i], s});
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; i++)
            if (cnt[i] == mx) ans.push_back(i);
        return ans;
    }
};
