class Solution {
public:
    int count =0;
    int mx = INT_MIN;
    void helper(TreeNode* root, int mx){
        if(root == NULL) return ;
        helper(root->left, max(mx,root->val));
        helper(root->right, max(mx,root->val));
        if(root->val >= mx){
            count += 1;
        }
    }
    int goodNodes(TreeNode* root) {
        helper(root,mx);
        return count;
    }
};