// #include<iostream>
// #include<vector>
//   struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode() : val(0), left(nullptr), right(nullptr) {}
//       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
//   };
 
class Solution
{
public:
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        TreeNode *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                res.emplace_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *node = curr->left;
                while (node->right && node->right != curr)
                {
                    node = node->right;
                }
                // if we on a left node of a right node 
                // then we first need to write the 
                // right node in the vector 
                if (!node->right)
                {
                    node->right = curr;
                    curr = curr->left;
                }
                // make the left node as it was initially
                else
                {
                    res.emplace_back(curr->val);
                    node->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};