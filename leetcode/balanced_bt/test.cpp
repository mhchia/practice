#include <iostream>
#include <vector>


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (isBalanced(root->left) && isBalanced(root->right) &&
            my_abs(GetHeight(root->left) - GetHeight(root->right)) <= 1) {
            return true;
        }
        return false;
    }
    int my_abs(int a) {
        return a > 0 ? a : -a;
    }
private:
    unordered_map<TreeNode*, size_t> tree_height;

    size_t GetHeight(TreeNode* root)
    {
        if (!root) return 0;
        decltype(tree_height.begin()) it = tree_height.find(root);
        if (it != tree_height.end()) return it->second;
        size_t height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
        tree_height[root] = height;
        return height;
    }
};

TreeNode* GetTree()
{
    TreeNode* root = new TreeNode();
}

void Inorder()
{

}

int main(void)
{


}

