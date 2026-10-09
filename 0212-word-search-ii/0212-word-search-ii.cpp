class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        struct TrieNode {
            TrieNode* child[26]{};
            string word = "";
        };

        TrieNode* root = new TrieNode();

        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->child[idx])
                    node->child[idx] = new TrieNode();
                node = node->child[idx];
            }
            node->word = word;
        }

        int m = board.size(), n = board[0].size();
        vector<string> ans;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        function<void(int, int, TrieNode*)> dfs =
            [&](int r, int c, TrieNode* node) {
                char ch = board[r][c];
                if (ch == '#' || !node->child[ch - 'a'])
                    return;

                node = node->child[ch - 'a'];

                if (!node->word.empty()) {
                    ans.push_back(node->word);
                    node->word = "";
                }

                board[r][c] = '#';

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n)
                        dfs(nr, nc, node);
                }

                board[r][c] = ch;
            };

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dfs(i, j, root);

        return ans;
    }
};