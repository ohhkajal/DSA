class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();

        int maxEnding = a[0];
        int minEnding = a[0];
        int ans = a[0];

        for (int i = 1; i < n; i++) {
            int v1=a[i];
            int v2=minEnding*a[i];
            int v3=maxEnding*a[i];
            maxEnding=max(v1,max(v2,v3));
            minEnding=min(v1,min(v2,v3));
            ans=max(ans,max(maxEnding,minEnding));

           
        }

        return ans;
    }
};