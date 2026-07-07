class Solution {
public:

    bool solve(int i, vector<int>& a, vector<int>& side, int target) {

        if(i == a.size()) {

            if(side[0] == target &&
               side[1] == target &&
               side[2] == target &&
               side[3] == target)
                return true;

            return false;
        }

        for(int j = 0; j < 4; j++) {

            if(side[j] + a[i] <= target) {

                side[j] += a[i];

                if(solve(i + 1, a, side, target))
                    return true;

                side[j] -= a[i];
            }
        }

        return false;
    }

    bool makesquare(vector<int>& a) {

        int sum = 0;

        for(int x : a)
            sum += x;

        if(sum % 4 != 0)
            return false;

        sort(a.rbegin(), a.rend());

        vector<int> side(4, 0);

        return solve(0, a, side, sum / 4);
    }
};