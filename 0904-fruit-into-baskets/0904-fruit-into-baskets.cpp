class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int high = 0;
        int n = fruits.size();

        unordered_map<int,int> f;
        int res = 0;

        for(high = 0; high < n; high++) {
            f[fruits[high]]++;

            while(f.size() > 2) {
                f[fruits[low]]--;
                if(f[fruits[low]] == 0)
                    f.erase(fruits[low]);
                low++;
            }

            res = max(res, high - low + 1);
        }

        return res;
    }
};