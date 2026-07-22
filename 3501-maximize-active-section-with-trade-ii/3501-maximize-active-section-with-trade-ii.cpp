class Solution {
public:
    struct Group {
        int start;
        int length;
    };

    class SparseTable {
    public:
        vector<vector<int>> st;

        SparseTable(vector<int>& a) {
            int n = a.size();
            int LOG = 1;

            while ((1 << LOG) <= n)
                LOG++;

            st.assign(LOG, vector<int>(n));

            for (int i = 0; i < n; i++)
                st[0][i] = a[i];

            for (int k = 1; k < LOG; k++) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    st[k][i] = max(
                        st[k - 1][i],
                        st[k - 1][i + (1 << (k - 1))]
                    );
                }
            }
        }

        int query(int l, int r) {
            int len = r - l + 1;
            int k = 31 - __builtin_clz(len);

            return max(
                st[k][l],
                st[k][r - (1 << k) + 1]
            );
        }
    };

    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>>& queries
    ) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');

        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0')
                    zeroGroups.back().length++;
                else
                    zeroGroups.push_back({i, 1});
            }

            zeroGroupIndex.push_back(zeroGroups.size() - 1);
        }

        if (zeroGroups.empty())
            return vector<int>(queries.size(), ones);

        vector<int> mergeLengths;

        for (int i = 0; i + 1 < zeroGroups.size(); i++) {
            mergeLengths.push_back(
                zeroGroups[i].length +
                zeroGroups[i + 1].length
            );
        }

        SparseTable st(mergeLengths);

        vector<int> answer;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int left = zeroGroupIndex[l] == -1
                ? -1
                : zeroGroups[zeroGroupIndex[l]].length -
                  (l - zeroGroups[zeroGroupIndex[l]].start);

            int right = zeroGroupIndex[r] == -1
                ? -1
                : r - zeroGroups[zeroGroupIndex[r]].start + 1;

            int start = zeroGroupIndex[l] + 1;

            int end = s[r] == '1'
                ? zeroGroupIndex[r]
                : zeroGroupIndex[r] - 1;

            int activeSections = ones;

            if (s[l] == '0' &&
                s[r] == '0' &&
                zeroGroupIndex[l] + 1 == zeroGroupIndex[r]) {

                activeSections = max(
                    activeSections,
                    ones + left + right
                );
            }
            else if (start <= end - 1) {
                activeSections = max(
                    activeSections,
                    ones + st.query(start, end - 1)
                );
            }

            if (s[l] == '0' &&
                zeroGroupIndex[l] + 1 <= end) {

                activeSections = max(
                    activeSections,
                    ones +
                    left +
                    zeroGroups[zeroGroupIndex[l] + 1].length
                );
            }

            if (s[r] == '0' &&
                zeroGroupIndex[l] < zeroGroupIndex[r] - 1) {

                activeSections = max(
                    activeSections,
                    ones +
                    right +
                    zeroGroups[zeroGroupIndex[r] - 1].length
                );
            }

            answer.push_back(activeSections);
        }

        return answer;
    }
};