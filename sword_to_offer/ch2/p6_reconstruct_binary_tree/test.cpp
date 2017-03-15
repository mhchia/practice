#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using namespace std;

int find_index(const vector<int>& ivec, int target)
{
    for (int i = 0; i < ivec.size(); ++i) {
        if (ivec[i] == target) {
            return i;
        }
    }
    return -1;
}

TreeNode* reconstruct_binary_tree(const vector<int>& preorder, const vector<int>& inorder,
                                  int pre_p1, int pre_p2, int in_p1, int in_p2)
{
    if (pre_p1 > pre_p2 || in_p1 > in_p2 || pre_p2 < 0 || in_p2 < 0 ||
        pre_p1 >= preorder.size() || in_p1 >= inorder.size()) {
        return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[pre_p1]);
    int root_pos_inorder = find_index(inorder, preorder[pre_p1]);
    if (root_pos_inorder == -1) throw runtime_error("preorder doesn't match inorder");
    node->left = reconstruct_binary_tree(preorder, inorder, pre_p1 + 1,
                                         pre_p1 + (root_pos_inorder - in_p1), in_p1, root_pos_inorder - 1
                 );
    node->right = reconstruct_binary_tree(preorder, inorder, pre_p1 + (root_pos_inorder - in_p1) + 1, pre_p2,
                                          root_pos_inorder + 1, in_p2
                  );
    return node;
}

void preorder_traverse(TreeNode* node)
{
    if (node) {
        cout << node->val << " ";
        preorder_traverse(node->left);
        preorder_traverse(node->right);
    }
}

void inorder_traverse(TreeNode* node)
{
    if (node) {
        inorder_traverse(node->left);
        cout << node->val << " ";
        inorder_traverse(node->right);
    }
}

int main(void)
{
    vector<int> inorder{2, 1, 4, 3};
    vector<int> preorder{1, 2, 3, 4};

    TreeNode* node = reconstruct_binary_tree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    preorder_traverse(node); puts("");
    inorder_traverse(node); puts("");

    return 0;
}

