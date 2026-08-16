class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};

        for (int x : stones)
            cnt[x % 3]++;

        // If there are no stones with remainder 1 or 2,
        // Alice cannot make a winning move.
        if (cnt[1] == 0 && cnt[2] == 0)
            return false;

        // If cnt[0] is even, Alice needs both types available.
        if (cnt[0] % 2 == 0)
            return cnt[1] > 0 && cnt[2] > 0;

        // If cnt[0] is odd, Alice can win if one remainder
        // type has at least 2 more stones than the other.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};