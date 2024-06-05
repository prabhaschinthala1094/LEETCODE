class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>freq1(26,0);
        for(auto j:words[0]){
            freq1[j-'a']++;
        } 
        for(int i=1;i<words.size();i++){
            vector<int>freq2(26,0);
            for(auto it:words[i])freq2[it-'a']++;
            for(int i=0;i<26;i++)freq1[i]=min(freq1[i],freq2[i]);
        }
        
        vector<string>ans;
        for(int i='a';i<='z';i++){
           while(freq1[i-'a']--){
                ans.push_back(string(1,i));
            }
        }
        return ans;
    }
};