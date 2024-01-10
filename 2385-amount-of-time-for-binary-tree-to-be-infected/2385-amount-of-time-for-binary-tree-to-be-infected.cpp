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
    unordered_map<int,vector<int>>mp;
    // TreeNode* node;
    void solve(TreeNode* root,int start){
        if(root==NULL)return;
        // if(root->val==start){
        //     node=root;
        // }
        if(root->left!=NULL){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
            solve(root->left,start);
        }
        if(root->right!=NULL){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
            solve(root->right,start);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        solve(root,start);
        queue<pair<int,int>>q;
        vector<bool>vis(1e5+5,0);
        vis[start]=1;
        int ans=0;
        q.push({0,start});
        // for(auto it:mp){
        //     cout<<it.first<<" -> ";
        //     for(auto k:it.second){
        //         cout<<k<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"in while "<<endl;
        while(!q.empty()){
            // int sz=mp[q.front().first].size();
            int value=q.front().first;
            int temp=q.front().second;
            // cout<<value<<" "<<temp<<endl;
            q.pop();
            for(auto &it: mp[temp]){
                if(!vis[it]){
                    // cout<<it<<endl;
                    q.push({value+1,it});
                    ans=max(value+1,ans);
                    vis[it]=1;
                }
            }
        }
        return ans;
        
    }
};