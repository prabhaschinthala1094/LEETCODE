class Solution {
public:
    static bool cmp(string &a, string &b) {
        return (a + b > b + a);  // Updated condition
    }

    string largestNumber(vector<int>& nums) {
        int p = 0;
        for (auto i : nums) {
            if (i == 0) {
                p++;
            }
        }
        int n = nums.size();
        if (p == n) return "0";
        vector<string> ans;
        for (auto it : nums) {
            ans.push_back(to_string(it));
        }
        sort(ans.begin(), ans.end(), cmp);
        string k;
        for (auto it : ans) k += it;
        return k;
    }
};
