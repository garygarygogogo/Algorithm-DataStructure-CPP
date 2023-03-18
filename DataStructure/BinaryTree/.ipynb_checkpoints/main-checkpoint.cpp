#incldue <iostream>
#incldue <vector>
#incldue <algorithm>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// preorder traversal
class Solution1 {
public:
    void traversal(TreeNode* cur, vector<int>& vec) { // 将整个树拆分成一个个的子树，针对每个子树进行根-->左-->右遍历
        if (cur == NULL) return;
        vec.push_back(cur->val);    // 根
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(n)

// inorderTraversal
class Solution2 {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {// 将整个树拆分成一个个的子树，针对每个子树进行左-->根-->右遍历
        if (cur == NULL) return;
        traversal(cur->left, vec);  // 左
        vec.push_back(cur->val);    // 根
        traversal(cur->right, vec); // 右
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 时间复杂度：O(n)
// 空间复杂度：O(n)

// sequentialTraversal
class Solution3 {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {// 将整个树拆分成一个个的子树，针对每个子树进行左-->右-->根遍历
        if (cur == NULL) return;
        traversal(cur->left, vec);  // 左
        traversal(cur->right, vec); // 右
        vec.push_back(cur->val);    // 根
    }
    vector<int> sequentialTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(n)

// sequential traversal by stack
class Solution4 {
public:
    vector<int> preorderTraversal(TreeNode* root) { // 前序遍历，口诀很好记：根-->左-->右。
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                res.emplace_back(node->val); // 前序遍历，先访问根
                stk.emplace(node);      
                node = node->left;           // 接下来进入左子树
            }
            if (!stk.empty()){
                node = stk.top();
                stk.pop();
                node = node->right;          // 接下来进入右子树
            }
        }
        return res;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(n)

// level order traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        queue<TreeNode*> que;            // 创建队列
        que.push(root);                  // 根节点先入队
        vector<vector<int>> res;
        while (!que.empty()){
            vector<int> vec;
            int len = que.size();
            for (int i=0; i<len; i++){
                TreeNode* node = que.front();
                vec.push_back(node->val);                       // 访问根节点
                que.pop();                                      // 根节点出队列
                if (node->left != NULL) que.push(node->left);   // 左节点入队
                if (node->right != NULL) que.push(node->right); // 右节点入队
            }
            res.push_back(vec);
        }
        return res;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(n)