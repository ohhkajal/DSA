class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0), gain(n + 1, 0);

        int minPrice = INT_MAX;

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                gain[i] += freq[j];
            }
            if (gain[i] > 0) gain[i]--;
        }

        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long remaining = budget;

        for (auto& item : items) {
            long long factor = item[0];
            long long price = item[1];

            if (price > 2LL * minPrice) break;

            long long cnt = min((long long)gain[factor],
                                remaining / price);

            ans += 2 * cnt;
            remaining -= cnt * price;
        }

        ans += remaining / minPrice;

        return (int)ans;
    }
};