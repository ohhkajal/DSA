
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), depth(n), heavy(n, -1), sz(n, 1);
        vector<int> head(n), pos(n), val(n);
        int timer = 0;

        function<void(int,int)> dfs = [&](int u, int p) {
            parent[u] = p;
            int best = 0;
            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > best) best = sz[v], heavy[u] = v;
            }
        };
        dfs(0, -1);

        function<void(int,int)> decompose = [&](int u, int h) {
            head[u] = h;
            pos[u] = timer++;
            val[pos[u]] = 1 << (s[u] - 'a');
            if (heavy[u] != -1) decompose(heavy[u], h);
            for (int v : adj[u]) {
                if (v != parent[u] && v != heavy[u])
                    decompose(v, v);
            }
        };
        decompose(0, 0);

        vector<int> seg(4 * n);
        function<void(int,int,int)> build = [&](int node, int l, int r) {
            if (l == r) {
                seg[node] = val[l];
                return;
            }
            int mid = (l + r) / 2;
            build(node * 2, l, mid);
            build(node * 2 + 1, mid + 1, r);
            seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
        };
        build(1, 0, n - 1);

        function<void(int,int,int,int,int)> update = [&](int node, int l, int r, int idx, int x) {
            if (l == r) {
                seg[node] = x;
                return;
            }
            int mid = (l + r) / 2;
            if (idx <= mid) update(node * 2, l, mid, idx, x);
            else update(node * 2 + 1, mid + 1, r, idx, x);
            seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
        };

        function<int(int,int,int,int,int)> query = [&](int node, int l, int r, int ql, int qr) -> int {
            if (ql <= l && r <= qr) return seg[node];
            int mid = (l + r) / 2, res = 0;
            if (ql <= mid) res ^= query(node * 2, l, mid, ql, qr);
            if (qr > mid) res ^= query(node * 2 + 1, mid + 1, r, ql, qr);
            return res;
        };

        auto pathQuery = [&](int u, int v) {
            int mask = 0;
            while (head[u] != head[v]) {
                if (depth[head[u]] < depth[head[v]]) swap(u, v);
                mask ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
                u = parent[head[u]];
            }
            if (depth[u] > depth[v]) swap(u, v);
            mask ^= query(1, 0, n - 1, pos[u], pos[v]);
            return mask;
        };

        vector<bool> ans;
        for (string& q : queries) {
            stringstream ss(q);
            string op;
            int u, v;
            ss >> op >> u;
            if (op == "update") {
                char c;
                ss >> c;
                s[u] = c;
                update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                ss >> v;
                int mask = pathQuery(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};
