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
//flatten BT to linked listclass Solution {
class Solution {
public:
    // This tracks the head of the flattened linked list formed so far
    TreeNode* nextRight = NULL; 

    void flatten(TreeNode* root) {
        // Base case: if node is null, do nothing
        if (root == NULL) {
            return;
        }

        // 1. Flatten the right subtree first
        flatten(root->right);

        // 2. Flatten the left subtree next
        flatten(root->left);

        // 3. Connect current node's right to the already flattened list
        root->right = nextRight;

        // 4. Set the left pointer to NULL
        root->left = NULL;

        // 5. Update nextRight to be the current root for the parent node call
        nextRight = root; 
    }
};