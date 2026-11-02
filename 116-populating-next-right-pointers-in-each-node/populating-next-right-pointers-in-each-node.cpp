/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

//populating next right pointers in each node

class Solution {
public:
    Node* connect(Node* root) {
        // Base case: if tree is empty or contains only a root node
        if (root == NULL || root->left == NULL) {
            return root;
        }
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL); // NULL acts as a level delimiter
        
        Node* prev = NULL;
        
        while (q.size() > 0) {
            Node* curr = q.front();
            q.pop();
            
            if (curr == NULL) {
                // If queue is empty, we have processed all levels
                if (q.size() == 0) {
                    break;
                }
                q.push(NULL);   // Append delimiter for the next level
                // prev = NULL;    // CRUCIAL: Reset prev to NULL for the new level
            } else {
                // Push left and right children to the queue
                if (curr->left != NULL) q.push(curr->left);
                if (curr->right != NULL) q.push(curr->right);
                if(prev!=NULL) prev->next = curr;

            }
            prev= curr;
            
        }
        
        return root;
    }
};