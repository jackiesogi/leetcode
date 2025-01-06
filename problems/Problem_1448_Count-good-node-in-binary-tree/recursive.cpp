@class Solution {
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* node, int largest) {
        if (!node) {
            return 0;
        }

        // Count the current node if it's a "good node"
        int count = (node->val >= largest) ? 1 : 0;

        // Update the largest value seen so far
        largest = max(largest, node->val);

        // Recur for left and right children
        count += dfs(node->left, largest);
        count += dfs(node->right, largest);

        return count;
    }
};

