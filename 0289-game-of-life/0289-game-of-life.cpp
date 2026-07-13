class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> temp = board;

        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                int live = 0;

                for(int k = 0; k < 8; k++) {

                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x >= 0 && x < m && y >= 0 && y < n && temp[x][y] == 1)
                        live++;
                }

                if(temp[i][j] == 1) {

                    if(live < 2 || live > 3)
                        board[i][j] = 0;
                }
                else {

                    if(live == 3)
                        board[i][j] = 1;
                }
            }
        }
    }
};