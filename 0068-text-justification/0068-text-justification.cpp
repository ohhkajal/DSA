class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> res;
        int n = words.size();
        int i = 0;

        while(i < n) {

            int j = i;
            int len = 0;

            while(j < n && len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            if(j == n || gaps == 0) {

                for(int k = i; k < j; k++) {
                    line += words[k];
                    if(k != j - 1)
                        line += " ";
                }

                while(line.size() < maxWidth)
                    line += " ";
            }
            else {

                int spaces = (maxWidth - len) / gaps;
                int extra = (maxWidth - len) % gaps;

                for(int k = i; k < j - 1; k++) {
                    line += words[k];

                    for(int p = 0; p < spaces; p++)
                        line += " ";

                    if(extra > 0) {
                        line += " ";
                        extra--;
                    }
                }

                line += words[j - 1];
            }

            res.push_back(line);
            i = j;
        }

        return res;
    }
};