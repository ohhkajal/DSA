class Solution {
public:
    bool canAliceWin(int n) {
        int moves = 10;
        bool alice = true;

        while (n >= moves) {
            n -= moves;
            moves--;
            alice = !alice;
        }

        return !alice;
    }
};