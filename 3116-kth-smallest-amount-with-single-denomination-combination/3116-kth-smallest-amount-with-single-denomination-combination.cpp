class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        coins.erase(unique(coins.begin(), coins.end()), coins.end());

        int n = coins.size();

        auto count = [&](long long x) {
            long long total = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = gcd(lcm, (long long)coins[i]);

                        if (lcm > x / (coins[i] / g)) {
                            valid = false;
                            break;
                        }

                        lcm = lcm / g * coins[i];
                    }
                }

                if (!valid || lcm > x)
                    continue;

                if (bits % 2)
                    total += x / lcm;
                else
                    total -= x / lcm;
            }

            return total;
        };

        long long low = 1;
        long long high = 1LL * coins[0] * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};