class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size();

        int noDel = a[0];
        int oneDel = a[0];
        int ans = a[0];

        for (int i = 1; i < n; i++) {
            int prevNoDel = noDel;
            int prevOneDel = oneDel;

            noDel = max(a[i], prevNoDel + a[i]);
            oneDel = max(prevNoDel, prevOneDel + a[i]);

            ans = max(ans, max(noDel, oneDel));
        }
        return ans;
    }
};