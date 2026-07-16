class Solution {
public:
    int binaryGap(int n) {

        int last = -1;
        int res = 0;
        int pos = 0;

        while(n > 0) {

            if(n & 1) {

                if(last != -1)
                    res = max(res, pos - last);

                last = pos;
            }

            n = n >> 1;
            pos++;
        }

        return res;
    }
};