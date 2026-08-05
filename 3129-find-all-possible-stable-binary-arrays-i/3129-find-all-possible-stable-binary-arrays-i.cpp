class Solution {
public:
    static const int MOD = 1e9 + 7;
    int dp[201][201][2];

    int solve(int zero, int one, int last, int limit) {
        if (dp[zero][one][last] != -1)
            return dp[zero][one][last];

        if (zero == 0)
            return dp[zero][one][last] = (last == 1 && one <= limit);

        if (one == 0)
            return dp[zero][one][last] = (last == 0 && zero <= limit);

        long long ans = 0;

        if (last == 0) {
            ans = solve(zero - 1, one, 0, limit);
            ans = (ans + solve(zero - 1, one, 1, limit)) % MOD;

            if (zero - limit - 1 >= 0)
                ans = (ans - solve(zero - limit - 1, one, 1, limit) + MOD) % MOD;
        } else {
            ans = solve(zero, one - 1, 0, limit);
            ans = (ans + solve(zero, one - 1, 1, limit)) % MOD;

            if (one - limit - 1 >= 0)
                ans = (ans - solve(zero, one - limit - 1, 0, limit) + MOD) % MOD;
        }

        return dp[zero][one][last] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));

        return (solve(zero, one, 0, limit) +
                solve(zero, one, 1, limit)) % MOD;
    }
};