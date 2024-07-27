TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *p=root;
        while(p){
            if(p->val==val) return p;
            else if(p->val<val)
                p=p->right;
            else 
                p=p->left;
        }
        return p;
}
