/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortList;
        // 中序遍历构造有序链表
        inOrder(root, sortList);
        // 有序链表构造平衡二叉树
        return buildTree(sortList, 0, sortList.size() - 1);
    }
private:
    void inOrder(TreeNode* node, vector<int> &sortList) {
        if (node != nullptr) {
            inOrder(node->left, sortList);
            sortList.push_back(node->val);
            inOrder(node->right, sortList);
        }
    }

// 有序链表构造平衡二叉树
    TreeNode* buildTree(vector<int> &sortList, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    // 中间节点为root
    int mid = (start + end)/2;
    TreeNode* root = new TreeNode(sortList[mid]);
    root->left = buildTree(sortList, start, mid - 1);
    root->right = buildTree(sortList, mid + 1, end);
    //
    return root;
}
};