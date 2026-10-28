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
//BT inorder traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        
        while (curr != NULL) {
            if (curr->left == NULL) {
                // If there is no left child, visit the node and move right
                ans.push_back(curr->val);
                curr = curr->right;
            } else { 
                // Find the Inorder Predecessor (IP)
                TreeNode* IP = curr->left;
                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }
                
                // --- MISSING LOGIC ADDED HERE ---
                if (IP->right == NULL) {
                    // Create a temporary thread back to current node
                    IP->right = curr;
                    curr = curr->left;
                } else {
                    // Thread already exists; break it and visit current node
                    IP->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};