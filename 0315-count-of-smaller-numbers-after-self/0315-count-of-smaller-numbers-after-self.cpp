class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), temp(n), idx(n);

        iota(idx.begin(), idx.end(), 0);

        function<void(int, int)> mergeSort = [&](int l, int r) {
            if (l >= r) return;

            int mid = l + (r - l) / 2;
            mergeSort(l, mid);
            mergeSort(mid + 1, r);

            int i = l, j = mid + 1, k = l;

            while (i <= mid && j <= r) {
                if (nums[idx[j]] < nums[idx[i]]) {
                    temp[k++] = idx[j++];
                } else {
                    ans[idx[i]] += j - (mid + 1);
                    temp[k++] = idx[i++];
                }
            }

            while (i <= mid) {
                ans[idx[i]] += j - (mid + 1);
                temp[k++] = idx[i++];
            }

            while (j <= r) {
                temp[k++] = idx[j++];
            }

            for (int p = l; p <= r; p++) {
                idx[p] = temp[p];
            }
        };

        mergeSort(0, n - 1);
        return ans;
    }
};