class Solution {
public:
    /* return <targetParent, target> */
    pair<TreeNode*, TreeNode*> binsearch(TreeNode *root, int key) {
        TreeNode *parent = nullptr;
        while (root) {
            if (root->val < key) {
                parent = root;
                root = root->right;
            } else if (root->val > key) {
                parent = root;
                root = root->left;
            } else {
                return {parent, root};
            }
        }
        return {nullptr, nullptr};
    }

    /* return <SuccessorParent, Successor> */
    pair<TreeNode*, TreeNode*> find_right_min(TreeNode *root) {
        TreeNode *parent = nullptr;
        TreeNode *successor = root->right;
        while (successor && successor->left) {
            parent = successor;
            successor = successor->left;
        }
        return {parent, successor};
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Find the target node and its parent
        auto [parent, target] = binsearch(root, key);
        if (!target) return root; // Key not found

        // Count children
        int childCount = 0;
        if (target->left) ++childCount;
        if (target->right) ++childCount;

        // Case 1: No children
        if (childCount == 0) {
            if (!parent) return nullptr; // Target is the root
            if (parent->left == target) parent->left = nullptr;
            else parent->right = nullptr;
            delete target;

        // Case 2: One child
        } else if (childCount == 1) {
            TreeNode *child = target->left ? target->left : target->right;
            if (!parent) root = child; // Target is the root
            else if (parent->left == target) parent->left = child;
            else parent->right = child;
            delete target;

        // Case 3: Two children
        } else {
            auto [successorParent, successor] = find_right_min(target);

            // Replace target's value with successor's value
            target->val = successor->val;

            // Delete the successor node
            if (successorParent) {
                successorParent->left = successor->right;
            } else {
                target->right = successor->right; // Successor is target->right
            }
            delete successor;
        }

        return root;
    }
};

