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
    int cnt=0;
        bool isPalindrome(vector<int>&path){
        int k=0;
        bool odd=0;
        bool even=0;
        // for(auto it:path)cout<<it<<" ";
        //          cout<<endl;
        for(auto it:path){
            if(it>0){
                k+=it;
                // var++;
            }
        }
        if(k==1||k==0)return 0;
        if(k&1){
            odd=1;
            bool found=0;
            for(auto it:path){
                if(it&1){
                    if(found)return 0;
                    else found=1;
                }
            }
        }
        else{ 
            even=1;
            for(auto it:path){
                if(it&1){
                    return 0;
                }
            }
        }
        return 1;   
    }
    void solve(TreeNode* root,vector<int>&path){
        if(root->left==NULL && root->right==NULL){
            path[root->val]++;
             if(isPalindrome(path)){
                 // for(auto it:path)cout<<it<<" ";
                 // cout<<endl;
                 cnt++;
             }
            path[root->val]--;
            return ;
        }
        path[root->val]++;
            if(root->left!=NULL)
            solve(root->left,path);
            if(root->right!=NULL)
            solve(root->right,path);
        path[root->val]--;
       
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root->right==NULL && root->left==NULL)return 1;
        vector<int>path(10,0);
        solve(root,path);
        return cnt;
    }
};