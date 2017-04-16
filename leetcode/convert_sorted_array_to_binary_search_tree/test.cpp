#include <iostream>
#include <vector>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a) : val(a), left(nullptr), right(nullptr) {}
};


TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    size_t mid = (nums.size() - 1) / 2;
    TreeNode* node = new TreeNode(nums[mid]);
    vector<int> left;
    for (size_t i = 0; i < mid; ++i) {
        left.push_back(nums[i]);
    }
    node->left = sortedArrayToBST(left);
    vector<int> right;
    for (size_t i = mid + 1; i < nums.size(); ++i) {
        right.push_back(nums[i]);
    }
    node->right = sortedArrayToBST(right);
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

int main(void)
{
    vector<int> ivec{1};
    TreeNode* node = sortedArrayToBST(ivec);

}

