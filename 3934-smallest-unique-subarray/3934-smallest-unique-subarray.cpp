class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n), lcp(n);
        iota(sa.begin(), sa.end(), 0);

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        for (int i = 0; i < n; i++) {
            rank[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();
        }

        for (int len = 1; len < n; len <<= 1) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int x = (a + len < n) ? rank[a + len] : -1;
                int y = (b + len < n) ? rank[b + len] : -1;
                return x < y;
            });

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1], b = sa[i];

                bool different = rank[a] != rank[b];

                int x = (a + len < n) ? rank[a + len] : -1;
                int y = (b + len < n) ? rank[b + len] : -1;

                if (x != y) different = true;

                temp[b] = temp[a] + different;
            }

            rank = temp;
            if (rank[sa[n - 1]] == n - 1) break;
        }

        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            if (r == 0) continue;

            int j = sa[r - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h])
                h++;

            lcp[r] = h;

            if (h > 0) h--;
        }

        int ans = n;

        for (int i = 0; i < n; i++) {
            int common = 0;

            if (i > 0)
                common = max(common, lcp[i]);

            if (i + 1 < n)
                common = max(common, lcp[i + 1]);

            if (common < n - sa[i])
                ans = min(ans, common + 1);
        }

        return ans;
    }
};