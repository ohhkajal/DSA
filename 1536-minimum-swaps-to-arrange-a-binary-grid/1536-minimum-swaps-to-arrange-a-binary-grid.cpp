class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailing(n);

        for (int i = 0; i < n; i++) {
            int j = n - 1;

            while (j >= 0 && grid[i][j] == 0)
                j--;

            trailing[i] = n - 1 - j;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int need = n - 1 - i;
            int j = i;

            while (j < n && trailing[j] < need)
                j++;

            if (j == n)
                return -1;

            while (j > i) {
                swap(trailing[j], trailing[j - 1]);
                j--;
                ans++;
            }
        }

        return ans;
    }
};