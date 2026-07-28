class Solution {
public:
    vector<vector<int>> g;
    int ans = 0;

    long long dfs(int u, int p, vector<int>& cost) {
        if (g[u].size() == 1 && p != -1)
            return cost[u];

        long long mx = 0;
        vector<long long> child;

        for (int v : g[u]) {
            if (v == p) continue;
            long long x = dfs(v, u, cost);
            child.push_back(x);
            mx = max(mx, x);
        }

        int cnt = 0;
        for (long long x : child)
            if (x < mx) cnt++;

        if (cnt == child.size()) {
            if (cnt > 0) ans++;
        } else {
            ans += cnt;
        }

        return cost[u] + mx;
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        if (n == 1) return 0;

        g.assign(n, {});

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        if (g[0].empty()) return 0;

        dfs(0, -1, cost);

        return ans;
    }
};