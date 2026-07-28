#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mult) {
        int FULL = (1 << n) - 1;
        const double INF = 1e18;

        auto encode = [&](int mask, int stage, int side) {
            return (mask * m + stage) * 2 + side;
        };

        int STATES = (1 << n) * m * 2;
        vector<double> dist(STATES, INF);

        priority_queue<pair<double,int>,
                       vector<pair<double,int>>,
                       greater<pair<double,int>>> pq;

        int start = encode(0, 0, 0);
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, state] = pq.top();
            pq.pop();

            if (d > dist[state] + 1e-12) continue;

            int side = state % 2;
            int x = state / 2;
            int stage = x % m;
            int mask = x / m;

            if (mask == FULL && side == 1)
                return d;

            if (side == 0) {
                int remain = FULL ^ mask;

                for (int sub = remain; sub; sub = (sub - 1) & remain) {
                    if (__builtin_popcount(sub) > k) continue;

                    int mx = 0;
                    for (int i = 0; i < n; i++) {
                        if (sub >> i & 1)
                            mx = max(mx, time[i]);
                    }

                    double cost = mx * mult[stage];
                    int ns = (stage + (int)floor(cost)) % m;
                    int nmask = mask | sub;
                    int nid = encode(nmask, ns, 1);

                    if (dist[nid] > d + cost + 1e-12) {
                        dist[nid] = d + cost;
                        pq.push({dist[nid], nid});
                    }
                }
            } else {
                for (int i = 0; i < n; i++) {
                    if (mask >> i & 1) {
                        double cost = time[i] * mult[stage];
                        int ns = (stage + (int)floor(cost)) % m;
                        int nmask = mask ^ (1 << i);
                        int nid = encode(nmask, ns, 0);

                        if (dist[nid] > d + cost + 1e-12) {
                            dist[nid] = d + cost;
                            pq.push({dist[nid], nid});
                        }
                    }
                }
            }
        }

        return -1.0;
    }
};