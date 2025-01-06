class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root; // Base case: return root if it's null, or if it's one of the target nodes (p or q)
        }

        // Recur for the left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Recur for the right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-null, root is the LCA
        if (left && right) {
            return root; // This means p is on one side and q is on the other, so root is the LCA
        }

        // If one side is null, the LCA is on the other side
        return left ? left : right; // If one side is null, return the non-null side
    }
};

