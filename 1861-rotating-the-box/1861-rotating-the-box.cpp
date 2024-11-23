class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>>ans(m,vector<char>(n,'.'));
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                ans[j][abs(n-i-1)]=box[i][j];
            }
        }
        for(int j=0;j<n;j++){
       
            for(int i=m-1;i>=0;i--){
                int gap = i;
                if(ans[i][j] == '.'){
                    while(i>0){
                        i--;
                        if(ans[i][j]=='#'){
                            swap(ans[gap][j],ans[i][j]);
                            i=gap;
                            break;
                        }
                        else if(ans[i][j]=='*'){
                            break;
                        }
                    }
                }
            }
        }
        for(auto i:ans){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        
        return ans;
    }
};