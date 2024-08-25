/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> helper(TreeNode* t, vector<int>& ans) { 
        if (t != NULL) {
            helper(t->left, ans);
            helper(t->right, ans);
            ans.push_back(t->val);
        }
        return ans;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans; 
        return helper(root, ans);
    }
};
