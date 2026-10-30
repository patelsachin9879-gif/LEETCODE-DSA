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
//build tree from preorder inorder

class Solution {
public:
    // Helper function from your notes to find the root's index in the inorder array
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    // Recursive function to construct the tree
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int inLeft, int inRight) {
        // Base case: if the range is invalid, return null
        if (inLeft > inRight) {
            return nullptr;
        }

       TreeNode* root = new TreeNode(preorder[preIdx]);
       int inIdx = search(inorder, inLeft, inRight, preorder[preIdx]);
       preIdx++;


        // Using the index from inorder, construct left and right subtrees
        root->left = buildTreeHelper(preorder, inorder, preIdx, inLeft, inIdx - 1);
        root->right = buildTreeHelper(preorder, inorder, preIdx, inIdx + 1, inRight);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return buildTreeHelper(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};