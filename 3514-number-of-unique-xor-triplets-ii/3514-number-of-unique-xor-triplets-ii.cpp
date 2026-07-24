class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int M = 2048;

        vector<bool> present(M, false);

        for (int x : nums)
            present[x] = true;

        vector<int> values;

        for (int x = 0; x < M; x++) {
            if (present[x])
                values.push_back(x);
        }

        vector<bool> pairXor(M, false);

        for (int x : values) {
            for (int y : values) {
                pairXor[x ^ y] = true;
            }
        }

        vector<bool> ans(M, false);

        for (int x = 0; x < M; x++) {
            if (pairXor[x]) {
                for (int y : values) {
                    ans[x ^ y] = true;
                }
            }
        }

        int count = 0;

        for (bool x : ans)
            count += x;

        return count;
    }
};