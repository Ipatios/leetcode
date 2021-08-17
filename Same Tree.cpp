#include<iostream>
/*
if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // if both trees are empty, return true
        // or if in the end of the tree
        if (p == nullptr && q == nullptr)
        {
            return 1;
        }

        // if both trees are non-empty and the value of their root node matches,
        // recur for their left and right subtree
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
int main(){
    Solution s;
        TreeNode *third = new TreeNode(3);
    TreeNode *second = new TreeNode(2);
    TreeNode* first = new TreeNode(1,second,third);

    TreeNode *third_ = new TreeNode(3);
    TreeNode *second_ = new TreeNode(2);
    TreeNode* first_ = new TreeNode(1,second_,third_);
    std::cout<<s.isSameTree(first,first_);
}
