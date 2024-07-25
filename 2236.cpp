bool checkTree(TreeNode* root) {
        return root->val==(root->left->val)+(root->right->val);
}
