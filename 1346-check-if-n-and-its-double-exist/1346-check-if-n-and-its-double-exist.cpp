class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        int c = 0;
        for(auto i:arr){
            if(i==0)c++;
            mp[i]++;
            
        }
        if(c==1)mp[0] = 0;
        for(int i=0;i<arr.size();i++){
        
                if(mp[2*arr[i]]>=1){
                    return 1;
                }
            
        }
        return 0;
    }
};