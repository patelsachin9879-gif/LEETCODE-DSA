/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//BST Iterator

class BSTIterator {
    public:
    stack<TreeNode*> s;

    // Helper function to push all left descendants
    void storeLeftNodes(TreeNode* root) {
        while (root != nullptr) {
            s.push(root);
            root = root->left;
        }
    }

    // Constructor initializes the iterator
    BSTIterator(TreeNode* root) {
        storeLeftNodes(root);
    }
    
    // Returns the next smallest number
    int next() {
        TreeNode* ans = s.top();
        s.pop();
        storeLeftNodes(ans->right);
        return ans->val;
    }
    
    // Returns whether we have a next smallest number
    bool hasNext() {
        return !s.empty(); 
    }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */