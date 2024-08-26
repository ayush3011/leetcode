/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> helper(Node* t, vector<int>& ans) {
        if (t != NULL) {
            for (int i = 0; i < t->children.size(); i++) {
                helper(t->children[i], ans);
            }
            ans.push_back(t->val);
        }
        return ans;
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        return helper(root, ans);
    }
};
