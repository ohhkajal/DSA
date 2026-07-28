class Solution {
public:
    bool isPrime(int x) {
        if (x < 2)
            return false;

        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }

        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int x : nums)
            mp[x]++;

        for (auto &it : mp) {
            if (isPrime(it.second))
                return true;
        }

        return false;
    }
};