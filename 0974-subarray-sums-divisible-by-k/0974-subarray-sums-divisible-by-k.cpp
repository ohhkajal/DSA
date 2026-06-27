class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {

        unordered_map<int,int> f;
        f[0] = 1;

        int sum = 0;
        int res = 0;

        for(int i = 0; i < a.size(); i++) {

            sum += a[i];

            int rem = sum % k;

            if(rem < 0)
                rem += k;

           res+=f[rem];

          

            f[rem]++;
        }

        return res;
    }
};