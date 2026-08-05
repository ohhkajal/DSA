class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n), rev(n);

        for (auto &e : invocations) {
            graph[e[0]].push_back(e[1]);
            rev[e[1]].push_back(e[0]);
        }

        vector<bool> suspicious(n, false);

        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = true;
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                continue;

            for (int p : rev[i]) {
                if (!suspicious[p]) {
                    vector<int> ans;
                    for (int j = 0; j < n; j++)
                        ans.push_back(j);
                    return ans;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};