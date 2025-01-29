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
    int dfs(TreeNode* node, int maxVal) {
        if (node == NULL)
            return 0;
            
        int result;

        if (node->val >= maxVal)
            result = 1;
        else
            result = 0;

        maxVal = max(maxVal, node->val);

        result += dfs(node->left, maxVal);
        result += dfs(node->right, maxVal);

        return result;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return dfs(root, root->val);
    }
};
