class Solution {
public:
    int ans = 0;

    void solve(TreeNode* root, int num) {
        if (!root) return;

        num = num * 2 + root->val;

        if (!root->left && !root->right) {
            ans += num;
            return;
        }

        solve(root->left, num);
        solve(root->right, num);
    }

    int sumRootToLeaf(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};