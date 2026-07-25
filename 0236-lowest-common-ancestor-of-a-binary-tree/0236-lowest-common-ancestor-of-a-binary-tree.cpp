class Solution {
public:
    bool exists(TreeNode* root ,TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;
        return exists(root->left,target) || exists(root->right, target);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root == p || root == q) return root;

        bool leftP = exists(root->left, p);
        bool leftQ = exists(root->left, q);

        if (leftP && leftQ)
            return lowestCommonAncestor(root->left, p, q);

        if (!leftP && !leftQ)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};