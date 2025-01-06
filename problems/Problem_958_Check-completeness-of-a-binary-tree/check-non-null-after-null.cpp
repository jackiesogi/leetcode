class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) {
            return true; // An empty tree is complete.
        }

        queue<TreeNode*> q;
        q.push(root);
        bool foundNull = false; // Flag to indicate if a null child has been encountered.

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (!current) {
                // Once a null child is encountered, all subsequent nodes must also be null.
                foundNull = true;
            } else {
                if (foundNull) {
                    // If we encounter a non-null node after a null node, the tree is not complete.
                    return false;
                }
                q.push(current->left);
                q.push(current->right);
            }
        }

        return true; // If we traverse the entire tree without issues, it is complete.
    }
};

