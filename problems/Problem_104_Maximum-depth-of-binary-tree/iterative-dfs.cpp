class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        stack<pair<TreeNode*, int>> s; // Pair of node and its depth
        s.push({root, 1});
        int maxDepth = 0;

        while (!s.empty()) {
            auto [node, depth] = s.top();
            s.pop();
            maxDepth = max(maxDepth, depth);

            if (node->left) {
                s.push({node->left, depth + 1});
            }
            if (node->right) {  /* right will be poped first in next iteration */
                s.push({node->right, depth + 1});
            }
        }

        return maxDepth;
    }
};

