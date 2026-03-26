/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    int maxSum = 0;

    Info dfs(TreeNode* root) {
        if (!root)
            return {true, 0, INT_MAX, INT_MIN};

        Info left  = dfs(root->left);
        Info right = dfs(root->right);

        // If left or right isn't BST OR violates BST rule
        if (!left.isBST || !right.isBST || left.maxVal >= root->val || right.minVal <= root->val) {
            return {false, 0, INT_MIN, INT_MAX};
        }

        int currSum = left.sum + right.sum + root->val;
        maxSum = max(maxSum, currSum);

        int currMin = min(root->val, left.minVal);
        int currMax = max(root->val, right.maxVal);

        return {true, currSum, currMin, currMax};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};