#include <iostream>
#include <stack>

#include "tree.hpp"

using namespace std;

void preorder_traverse_recursively(TreeNode* node)
{
    if (!node) return;
    cout << node->val << " ";
    preorder_traverse_recursively(node->left);
    preorder_traverse_recursively(node->right);
}


// just dfs
void preorder_traverse_iteratively(TreeNode* node)
{
    if (!node) return;
    stack<TreeNode*> s;
    s.push(node);
    while (!s.empty()) {
        TreeNode* now = s.top();
        s.pop();
        cout << now->val << " ";
        // left is print before right
        if (now->right) s.push(now->right);
        if (now->left) s.push(now->left);
    }
}



TreeNode* create_bt_normal()
{
    TreeNode* node = new TreeNode(2);
    node->left = new TreeNode(1);
    node->right = new TreeNode(3);
    return node;
}

TreeNode* create_bt_one_node()
{
    return new TreeNode(1);
}

void test_preorder_traverse_iteratively()
{
    TreeNode* node = create_bt_normal();
    preorder_traverse_iteratively(node);
    cout << endl;
}
void test_preorder_traverse_recursively()
{
    TreeNode* node = create_bt_normal();
    preorder_traverse_recursively(node);
    cout << endl;
}

int main(void)
{
    test_preorder_traverse_iteratively();
//    test_preorder_traverse_recursively();
}

