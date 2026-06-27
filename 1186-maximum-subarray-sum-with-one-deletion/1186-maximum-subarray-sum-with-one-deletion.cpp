class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size();

        int noDel = a[0];
        int oneDel = 0;
        int ans = a[0];

        for(int i = 1; i < n; i++) {

            oneDel = max(noDel, oneDel + a[i]);
            noDel = max(a[i], noDel + a[i]);

            ans = max(ans, max(noDel, oneDel));
        }

        return ans;
    }
};