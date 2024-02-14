class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int p=n/2;
        vector<int>neg(p,0),pos(p,0);
        int j=0,k=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0){
                pos[j++]=i;
            }
            else{
                neg[k++]=i;
            }
        }
        vector<int>ans;
        int i=0;
        int m=0;
        int cnt=0;
        while(cnt<n )
        {
            if(cnt%2==0)
            {
                ans.push_back(nums[pos[i++]]);
                cnt++;
            }
            if(cnt%2!=0)
            {
                ans.push_back(nums[neg[m++]]);
                cnt++;
            }
        }
        return ans;
        
    }
};