class Solution {
public:
    int moves =0;
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int left= helper(root->left);
        int right= helper(root->right);
        int coins = root->val + right + left -1;
        moves += abs(left) + abs(right);
        return coins;
    }
    int distributeCoins(TreeNode* root) {
        helper(root);
        return moves;
    }
};