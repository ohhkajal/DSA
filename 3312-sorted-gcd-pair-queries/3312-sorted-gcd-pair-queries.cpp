class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);

        for(int x : nums)
            freq[x]++;

        vector<long long> cnt(mx + 1, 0);

        for(int g = 1; g <= mx; g++) {

            long long total = 0;

            for(int j = g; j <= mx; j += g)
                total += freq[j];

            cnt[g] = total * (total - 1) / 2;
        }

        for(int g = mx; g >= 1; g--) {

            for(int j = 2 * g; j <= mx; j += g)
                cnt[g] -= cnt[j];
        }

        vector<long long> prefix(mx + 1, 0);

        for(int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + cnt[i];

        vector<int> res;

        for(long long q : queries) {

            int low = 1;
            int high = mx;

            while(low < high) {

                int mid = low + (high - low) / 2;

                if(prefix[mid] > q)
                    high = mid;
                else
                    low = mid + 1;
            }

            res.push_back(low);
        }

        return res;
    }
};