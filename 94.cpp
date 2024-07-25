void Inorder(TreeNode* root, vector<int>& ans){
        if(root != nullptr){
            Inorder(root->left, ans);
            ans.push_back(root->val);
            Inorder(root->right, ans);
        }
}
    
vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        Inorder(root, ans);
        return ans;
}
