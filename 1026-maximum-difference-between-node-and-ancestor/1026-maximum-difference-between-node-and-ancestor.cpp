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
    int ans=0;
    void solve(TreeNode* node,int maxi,int mini){
        if(node==NULL){
            ans=max(ans,maxi-mini);
            // maxi=0;
            // mini=0;
            return ;
        }
        maxi=max(maxi,node->val);
        mini=min(mini,node->val);
        solve(node->left,maxi,mini);
        solve(node->right,maxi,mini);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root,root->val,root->val);
        return ans;
    }
};