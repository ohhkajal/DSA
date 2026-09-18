class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        
        vector<int> first(26, n), last(26, -1);
        
        // First and last occurrence of every character
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            first[x] = min(first[x], i);
            last[x] = i;
        }
        
        vector<pair<int,int>> intervals;
        
        // Find valid interval for each character
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1) continue;
            
            int l = first[c];
            int r = last[c];
            bool valid = true;
            
            for (int i = l; i <= r; i++) {
                int x = s[i] - 'a';
                
                // Character occurs before l, so interval is invalid
                if (first[x] < l) {
                    valid = false;
                    break;
                }
                
                r = max(r, last[x]);
            }
            
            if (valid)
                intervals.push_back({l, r});
        }
        
        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });
        
        vector<string> ans;
        int prevEnd = -1;
        
        // Greedily choose earliest-ending intervals
        for (auto [l, r] : intervals) {
            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }
        
        return ans;
    }
};