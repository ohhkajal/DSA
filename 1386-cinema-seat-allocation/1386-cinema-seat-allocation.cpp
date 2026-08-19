class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;

        for (auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9)
                reserved[row] |= (1 << col);
        }

        int ans = (n - reserved.size()) * 2;

        for (auto& [row, mask] : reserved) {
            int count = 0;

            bool left = true, middle = true, right = true;

            for (int col = 2; col <= 5; col++)
                if (mask & (1 << col))
                    left = false;

            for (int col = 4; col <= 7; col++)
                if (mask & (1 << col))
                    middle = false;

            for (int col = 6; col <= 9; col++)
                if (mask & (1 << col))
                    right = false;

            if (left && right)
                count = 2;
            else if (left || middle || right)
                count = 1;

            ans += count;
        }

        return ans;
    }
};