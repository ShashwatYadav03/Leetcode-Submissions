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
    vector<int> ans;

    TreeNode* prev = nullptr;

    int count = 0;
    int maxCount = 0;

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;

        // Left
        inorder(root->left);

        // Current node
        if (prev != nullptr && prev->val == root->val) {
            count++;
        } else {
            count = 1;
        }

        // New maximum frequency
        if (count > maxCount) {
            maxCount = count;
            ans.clear();
            ans.push_back(root->val);
        }
        // Same maximum frequency
        else if (count == maxCount) {
            ans.push_back(root->val);
        }

        prev = root;

        // Right
        inorder(root->right);
    }

};