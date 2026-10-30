
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        string mavorqeli = labels;

        const long long INF = LLONG_MAX;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, cnt] = pq.top();
            pq.pop();

            if (cost != dist[u][cnt]) continue;

            if (u == n - 1) return cost;

            for (auto [v, w] : adj[u]) {
                int nextCnt = (mavorqeli[u] == mavorqeli[v]) ? cnt + 1 : 1;

                if (nextCnt > k) continue;

                long long newCost = cost + w;

                if (newCost < dist[v][nextCnt]) {
                    dist[v][nextCnt] = newCost;
                    pq.push({newCost, v, nextCnt});
                }
            }
        }

        return -1;
    }
};
