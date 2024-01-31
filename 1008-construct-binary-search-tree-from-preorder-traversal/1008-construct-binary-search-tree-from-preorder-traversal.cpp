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
    TreeNode* solve(int &ind,vector<int>&preorder,int mini,int maxi) {
        if(ind>=preorder.size())return NULL;
        if(preorder[ind]<mini || preorder[ind]>maxi)return NULL;
        TreeNode*root=new TreeNode(preorder[ind++]);
        root->left=solve(ind,preorder,mini,root->val);
        root->right=solve(ind,preorder,root->val,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind=0;
        TreeNode* ans=solve(ind,preorder,INT_MIN,INT_MAX);
        return ans;
    }
};