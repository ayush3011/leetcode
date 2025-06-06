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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;

        int bottomLeft;
        que.push(root);

        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            bottomLeft = node->val;

            if (node->right) {
                que.push(node->right);
            }
            if (node->left) {
                que.push(node->left);
            }
        }
        return bottomLeft;
    }
};
