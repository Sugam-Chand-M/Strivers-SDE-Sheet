// https://leetcode.com/problems/count-complete-tree-nodes/

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
    int findLeftHeight(TreeNode* node)
    {
        int height=0;
        while(node)
        {
            height++;
            node=node->left;
        }
        return height;
    }
    int findRightHeight(TreeNode* node)
    {
        int height=0;
        while(node)
        {
            height++;
            node=node->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int left=findLeftHeight(root);
        int right=findRightHeight(root);
        if(left==right)
            return (1<<left)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};

