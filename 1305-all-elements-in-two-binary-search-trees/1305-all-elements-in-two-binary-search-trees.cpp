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
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr)
            return;
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b, ans;

        // Get sorted elements from both BSTs
        inorder(root1, a);
        inorder(root2, b);

        // Merge two sorted arrays
        int i = 0;
        int j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }

        // Remaining elements of a
        while (i < a.size()) {
            ans.push_back(a[i]);
            i++;
        }

        // Remaining elements of b
        while (j < b.size()) {
            ans.push_back(b[j]);
            j++;
        }

        return ans;
    }
};