class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {

        int n = a.size();
        int first = -1;
        int last = -1;

        int low = 0;
        int high = n - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(a[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if(a[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        low = 0;
        high = n - 1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(a[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if(a[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return {first, last};
    }
};