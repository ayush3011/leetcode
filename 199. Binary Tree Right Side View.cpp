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
    // Using Level Order Traversal, BFS
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {};

        // queue to store the node
        queue<TreeNode*> que;
        que.push(root);
        vector<int> ans;

        // while we find nodes
        while (!que.empty()) {
            int n = que.size();
            TreeNode* node = NULL;

            // looping current level nodes
            while (n--) {
                node = que.front();
                que.pop();

                if (node->left != NULL)
                    que.push(node->left);
                if (node->right != NULL)
                    que.push(node->right);
            }
            // pushing the rightmost node in the ans array
            ans.push_back(node->val);
        }

        return ans;
    }
};
