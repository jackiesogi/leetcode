class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            TreeNode *last_node = nullptr;

            for (int i = 0; i < level_size; ++i) {
                TreeNode* current = q.front();
                q.pop();

                // Update the last node seen at this level
                last_node = current;

                // Add children of the current node to the queue
                if (current->left) {
                    q.push(current->left);
                }
                if (current->right) {
                    q.push(current->right);
                }
            }

            // Add the last node's value to the result
            result.push_back(last_node->val);
        }

        return result;
    }
};

