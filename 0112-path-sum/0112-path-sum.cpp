class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root == NULL)
            return false;

        if(root->left == NULL && root->right == NULL) {

            if(targetSum == root->val)
                return true;

            return false;
        }

        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};