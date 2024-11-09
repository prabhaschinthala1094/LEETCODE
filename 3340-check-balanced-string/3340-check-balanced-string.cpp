class Solution {
public:
    bool isBalanced(string num) {
        int n= num.size();
        int val = 0;
        for(int i=0;i<n;i+=2){
            val+=((num[i]-'0') - ((i<n-1)?(num[i+1]-'0'):0));
            // cout<<(num[i]-'0')<<" "<<((i<n-1)?(num[i+1]-'0'):0)<<" "<<val<<endl;
        }
        return (val == 0);
    }
};