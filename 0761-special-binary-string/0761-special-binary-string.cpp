class Solution {
public:
    string makeLargestSpecial(string s) {

        vector<string> v;

        int count = 0;
        int start = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '1')
                count++;
            else
                count--;

            if(count == 0) {

                string inner = s.substr(start + 1, i - start - 1);

                v.push_back("1" + makeLargestSpecial(inner) + "0");

                start = i + 1;
            }
        }

        sort(v.begin(), v.end(), greater<string>());

        string res = "";

        for(string x : v)
            res += x;

        return res;
    }
};