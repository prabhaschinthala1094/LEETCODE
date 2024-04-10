class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 1,e = n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int cnt =0;
            for(auto it:nums){
                if(it <= mid)cnt++;
            }
            if(cnt>mid){
                e = mid -1;
            }
            else{
                s = mid +1;
            }
        }
        return s;
    }
};