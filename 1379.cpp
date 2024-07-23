TreeNode* preOrder(TreeNode* cloned, int value){
        if(cloned!=NULL){
            if (cloned->val == value) return cloned;
        
            TreeNode* leftResult = preOrder(cloned->left, value);
            if (leftResult != NULL) 
                return leftResult;
                
            TreeNode* rightResult = preOrder(cloned->right, value);
            if (rightResult != NULL) 
                return rightResult;
        }
        return NULL;
}
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return preOrder(cloned, target->val);
}
