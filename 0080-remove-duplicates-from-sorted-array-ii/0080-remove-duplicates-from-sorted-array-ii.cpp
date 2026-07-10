class Solution {
public:
    int removeDuplicates(vector<int>& a) {

        int n = a.size();

        if(n <= 2)
            return n;

        int i = 2;

        for(int j = 2; j < n; j++) {

            if(a[j] != a[i - 2]) {
                a[i] = a[j];
                i++;
            }
        }

        return i;
    }
};