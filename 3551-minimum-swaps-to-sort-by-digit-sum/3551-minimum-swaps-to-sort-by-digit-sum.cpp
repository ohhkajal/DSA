class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> sorted;

        for (int x : nums)
            sorted.push_back({digitSum(x), x});

        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++)
            pos[sorted[i].second] = i;

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || pos[nums[i]] == i)
                continue;

            int j = i, cycle = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = pos[nums[j]];
                cycle++;
            }

            ans += cycle - 1;
        }

        return ans;
    }
};