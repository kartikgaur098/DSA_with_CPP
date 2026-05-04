class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char curr = s[i];
            if (ans.empty() || curr != ans.back()) {
                ans.push_back(curr);
            }
            else if(curr == ans.back()) 
            { 
                ans.pop_back();
            }
        }
        return ans;
    }
};