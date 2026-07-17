class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n=a.size();
        int bestending=a[0];
        int ans=a[0];
        for(int i=1;i<n;i++){
            int v1=bestending+a[i];
            int v2=a[i];
            bestending=max(v1,v2);
            ans=max(bestending,ans);
        }
        return ans;   
    }
};