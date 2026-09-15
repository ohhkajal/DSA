class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int n = 0, south = 0, e = 0, w = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'N') n++;
            else if (s[i] == 'S') south++;
            else if (s[i] == 'E') e++;
            else w++;

            int len = i + 1;

            int bad1 = south + w; // Target: North + East
            int bad2 = south + e; // Target: North + West
            int bad3 = n + w;     // Target: South + East
            int bad4 = n + e;     // Target: South + West

            ans = max(ans, len - 2 * bad1 + 2 * min(k, bad1));
            ans = max(ans, len - 2 * bad2 + 2 * min(k, bad2));
            ans = max(ans, len - 2 * bad3 + 2 * min(k, bad3));
            ans = max(ans, len - 2 * bad4 + 2 * min(k, bad4));
        }

        return ans;
    }
};