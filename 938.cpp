int preOrder(TreeNode* root, int low, int high) {
        int ans=0;
        if (root != NULL) {
            if (root->val >= low && root->val <= high) ans += root->val;
            ans+=preOrder(root->left, low, high);
            ans+=preOrder(root->right, low, high);
        }
        return ans;
}

int rangeSumBST(TreeNode* root, int low, int high) {
        return preOrder(root, low, high);
}
