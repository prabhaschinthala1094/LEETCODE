class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxi=min(height[n-1],height[0])*(n-1);
        int i=0,j=n-1;
        while(i<=j){
            int curr=min(height[i],height[j])*(j-i);
            maxi=max(curr,maxi);
            if(height[i]<=height[j])i++;
            else j--;
        }
        return maxi;
        
    }
};