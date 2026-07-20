class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> a;

        for (auto &row : grid)
            for (int x : row)
                a.push_back(x);

        int total = m * n;
        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < total; i++) {
            int newIndex = (i + k) % total;
            ans[newIndex / n][newIndex % n] = a[i];
        }

        return ans;
    }
};