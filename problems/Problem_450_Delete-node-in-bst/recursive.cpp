class Solution {
public:
    TreeNode* findMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
       if (!root) {
            return nullptr;
       }

       if (root->val < key) {
            root->right = deleteNode(root->right, key);
       } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
       } else {
            // Case 1: no child
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            // Case 2: one child
            else if (!root->left || !root->right) {
                TreeNode *temp = (root->left) ? root->left : root->right;
                delete root;
                return temp;
            }
            // Case 3: two children
            else {
                TreeNode *succ = findMin(root->right);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
       }
       return root;
    }
};

