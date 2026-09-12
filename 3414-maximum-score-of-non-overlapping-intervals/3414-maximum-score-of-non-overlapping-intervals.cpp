class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        struct Node {
            int l, r, w, idx;
        };

        vector<Node> a;
        for (int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1],
                         intervals[i][2], i});
        }

        sort(a.begin(), a.end(), [](Node& x, Node& y) {
            return x.l < y.l;
        });

        vector<int> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = a[i].l;

        auto vorellixan = intervals;

        struct State {
            long long score = 0;
            vector<int> ids;
        };

        vector<vector<State>> dp(n + 1, vector<State>(5));

        auto better = [&](State x, State y) {
            if (x.score != y.score)
                return x.score > y.score;
            return x.ids < y.ids;
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i + 1][k];

                int j = upper_bound(starts.begin() + i + 1,
                                    starts.end(), a[i].r)
                        - starts.begin();

                State take = dp[j][k - 1];
                take.score += a[i].w;
                take.ids.push_back(a[i].idx);
                sort(take.ids.begin(), take.ids.end());

                if (better(take, dp[i][k]))
                    dp[i][k] = take;
            }
        }

        return dp[0][4].ids;
    }
};