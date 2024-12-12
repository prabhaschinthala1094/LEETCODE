class Solution {
public:
 
int maximumLength(string s) {
    int longest = -1;
    unordered_map<string, int> counts;

    for (int i = 0; i < s.length(); ++i) {
        for (int j = i ; j < s.length(); ++j) {
           string substr = s.substr(i, j - i + 1);
            bool isSpecial = true;
            for (int k = 1; k < substr.size(); ++k) {
                if (substr[k] != substr[0]) {
                    isSpecial = false;
                    break;
                }
            }
            if (isSpecial) {
                counts[substr]++;
                if (counts[substr] >= 3) {
                    longest = max(longest, (int)substr.size());
                }
            }
        }
    }

    return longest;
}
};