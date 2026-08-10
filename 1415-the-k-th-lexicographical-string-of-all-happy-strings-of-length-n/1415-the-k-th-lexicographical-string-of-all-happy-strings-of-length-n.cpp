class Solution {
public:
    string ans = "";
    int count = 0;

    void solve(int n, int k, string curr) {
        if (curr.size() == n) {
            count++;

            if (count == k)
                ans = curr;

            return;
        }

        for (char c = 'a'; c <= 'c'; c++) {
            if (!curr.empty() && curr.back() == c)
                continue;

            solve(n, k, curr + c);

            if (!ans.empty())
                return;
        }
    }

    string getHappyString(int n, int k) {
        solve(n, k, "");
        return ans;
    }
};