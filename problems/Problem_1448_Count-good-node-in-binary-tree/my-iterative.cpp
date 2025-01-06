class Solution {
public:
    int goodNodes(TreeNode* root) {
        int result = 0;

        stack<pair<TreeNode*, int>> s; //<treenode, largest>
        s.push({root, INT_MIN});
        while(!s.empty()) {
            auto [node, largest] = s.top();
            s.pop();
            if (node->val >= largest) {
                largest = node->val;
                ++result;
            }
            if (node->right) {
                s.push({node->right, largest});
            }
            if (node->left) {
                s.push({node->left, largest});
            }
        }
        return result;
    }
};
